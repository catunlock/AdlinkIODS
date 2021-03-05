
#pragma once

#include "OutputDeviceInterface.h"
#include "OutputDevicePSDASK.h"

class OutputDevice6202 : public OutputDevicePSDASK
{

public:
    OutputDevice6202(CommonDeviceInterface *commonDevice) : OutputDevicePSDASK(commonDevice)
    {
    }

    virtual bool supports_continuous_output() const override;
    virtual void config(U16 d2k_configCtrl, U16 d2k_trgCtrl, U32 reTrgCnt, U32 DLY1Cnt, U32 DLY2Cnt, bool autoResetBuf) override;
};