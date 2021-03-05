#include "OutputDevice6202.h"

bool OutputDevice6202::supports_continuous_output() const
{
    return true;
}

void OutputDevice6202::config(U16 d2k_configCtrl, U16 d2k_trgCtrl, U32 reTrgCnt, U32 DLY1Cnt, U32 DLY2Cnt, bool autoResetBuf)
{
    // for D2K DLYXCnt are U16; For 6202 are U32

    U16 configCtrl = 0;
    U16 trgCtrl = d2k_trgCtrl;

    assert(P6202_DA_WRSRC_Int == DAQ2K_DA_WRSRC_Int);
    assert(P6202_DA_WRSRC_AFI0 == DAQ2K_DA_WRSRC_AFI0);
    assert(P6202_DA_WRSRC_SSI == DAQ2K_DA_WRSRC_SSI);

    assert(P6202_DA_TRGMOD_DELAY == DAQ2K_DA_TRGMOD_DELAY);
    assert(P6202_DA_TRGMOD_POST == DAQ2K_DA_TRGMOD_POST);
    assert(P6202_DA_ReTrigEn == DAQ2K_DA_ReTrigEn);
    const U16 d2kValidBits = P6202_DA_TRGMOD_DELAY | P6202_DA_TRGMOD_POST | P6202_DA_ReTrigEn;

    U16 d2ksrc = d2k_trgCtrl & 0x3;
    if (d2ksrc == DAQ2K_DA_TRGSRC_SOFT)
        trgCtrl |= P6202_DA_TRGSRC_SOFT;
    else if (d2ksrc == DAQ2K_DA_TRSRC_SSI)
        trgCtrl |= P6202_DA_TRGSRC_SSI;
    else
        throw_error("Adlink ERROR",
                    "Unsupported option for trigger source.\n"
                    "This board does not support current configuration.",
                    _CFN_);
    /// @todo WARNING Rethink this, because we are using D2K as base, and complaining if it is not supported by PCIDASK... but PCIDASK also supports some things that are not in D2K!!

    trgCtrl |= (d2k_trgCtrl & d2kValidBits);

    if (d2k_trgCtrl & ~(d2kValidBits | 0x3))
        throw_error("Adlink ERROR",
                    "Unexpected option in trigger control.\n"
                    "This board does not support current configuration.",
                    _CFN_);

    adlink_assert(AO_6202_Config(this->handler(),
                                 configCtrl,
                                 trgCtrl,
                                 reTrgCnt,
                                 DLY1Cnt,
                                 DLY2Cnt,
                                 BOOLEAN(autoResetBuf)));
}