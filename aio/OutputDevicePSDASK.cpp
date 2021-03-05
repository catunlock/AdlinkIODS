#include "OutputDevicePSDASK.h"

void OutputDevicePSDASK::cont_buffer_compose(U16 wChannel, U32 dwUpdateCount, void *_conBuffer, void *_buffer)
{
    // Based on D2K_AO_ContBufferCompose, it's just that PSDASK does not
    // provide an equivalent!
    assert(wChannel < this->type_params()->aoChannels);

    U16 *inBuf = reinterpret_cast<U16 *>(_buffer);
    U16 *outBuf = reinterpret_cast<U16 *>(_conBuffer);

    U16 total_channels = this->type_params()->aoChannels;

    for (U32 k = 0; k < dwUpdateCount; ++k)
    {
        //((U16*) ConBuffer)[k*2+wChannel] = ((U16 *) pwBuffer)[k];
        outBuf[k * total_channels + wChannel] = inBuf[k];
    }
}

bool OutputDevicePSDASK::supports_continuous_output() const
{
    return false;
}

void OutputDevicePSDASK::config(U16 d2k_configCtrl, U16 d2k_trgCtrl, U32 reTrgCnt, U32 DLY1Cnt, U32 DLY2Cnt, bool autoResetBuf)
{
    if ((d2k_trgCtrl != 0) || (d2k_configCtrl != 0) || (reTrgCnt != 0) || (DLY1Cnt != 0) || (DLY2Cnt != 0))
        throw_error("Adlink ERROR",
                    "Current configuration is not supported by this board.",
                    _CFN_);
}

U32 OutputDevicePSDASK::initial_memory_allocated_kb()
{
    U32 memSize;
    // TODO: Check why this produces a core dump /coredump / core-dump
    adlink_assert(AO_InitialMemoryAllocated(this->handler(), &memSize));
    return memSize;
}

/// Even though now the only PSDASK board supporting continuous mode is 6202
/// (OutputDevice6202) most of it's functionality is defined here, so it will
/// already be common in case some new card arrives.

U16 OutputDevicePSDASK::cont_buffer_setup(void *buffer, U32 writeCnt)
{
    writeCnt = writeCnt / 2; /// @todo Try to understand why, not just "because it's the only way it works" Same in cont_write_multi_channels

    printf("AO_ContBufferSetup (%d, %d, %d, bufferId)\n", handler(), buffer, writeCnt);
    U16 bufId;
    adlink_assert(AO_ContBufferSetup(this->handler(), buffer, writeCnt, &bufId));
    printf("  -> bufferId = %d", bufId);
    return bufId;
}

void OutputDevicePSDASK::async_check(bool &isStopped, U32 &accesCnt)
{
    BOOLEAN _isStopped;
    adlink_assert(AO_AsyncCheck(handler(), &_isStopped, &accesCnt));
    isStopped = _isStopped;
}

U32 OutputDevicePSDASK::async_clear()
{
    U32 count;
    AO_AsyncClear(this->handler(), &count, 0);
    return count;
}

void OutputDevicePSDASK::reset_buffers()
{
    adlink_assert(AO_ContBufferReset(this->handler()));
}

void OutputDevicePSDASK::configure_channel_range(U16 channel, U16 range_id)
{
    if (range_id != AD_B_10_V)
    {
        throw_error("Adlink ERROR",
                    "Unsupported range. Only valid value is (-10,10)",
                    _CFN_);
    }
}

void OutputDevicePSDASK::write_channel(U16 channel, U16 value)
{
    info() << "AO_WriteChannel(" << channel << ", " << value << ")" << std::endl;
    adlink_assert(AO_WriteChannel(handler(), channel, value));
}

void OutputDevicePSDASK::cont_write_multi_channels(U16 nchannels, U16 *chanBufIDs, U16 bufId, U32 writeCnt, U32 iterations, U32 CHUI, bool infinite, U16 syncMode)
{
    /// @todo Try to understand why I put these /2, not just "because it's the only way it works" Same in cont_buffer_setup
    U16 definite = infinite ? 0 : 1;
    printf("AO_ContWriteMultiChannels (%d,%d,%d,%d,%d,%d,%d,%d, %d)\n",
           this->handler(),      // U16 wCardNumber
           nchannels,            // U16 wNumChans
           chanBufIDs,           // U16 *pwChans
           bufId,                // U16 bufId
           writeCnt / 2,         // U32 dwUpdateCount
           iterations,           // U32 wIterations
           CHUI * nchannels / 2, // U32 dwCHUI
           definite,             // U16 definite
           syncMode);            // U16 wSyncMode
    adlink_assert(AO_ContWriteMultiChannels(
        this->handler(),      // U16 wCardNumber
        nchannels,            // U16 wNumChans
        chanBufIDs,           // U16 *pwChans
        bufId,                // U16 bufId
        writeCnt / 2,         // U32 dwUpdateCount
        iterations,           // U32 wIterations
        CHUI * nchannels / 2, // U32 dwCHUI
        definite,             // U16 definite
        syncMode));           // U16 wSyncMode
}