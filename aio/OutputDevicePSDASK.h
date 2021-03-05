
#pragma once
#include <stdint.h>
#include "AdlHelp.h"
#include "InputDeviceInterface.h"
#include "AdlDeviceFactorySingleton.h"
#include <vector>
#include <cassert>
#include <cmath>

#include "OutputDeviceInterface.h"

#define _OCLASSNAME "InputDevicePSDASK"
#include "odebug.h"
#include <dask.h>

class OutputDevicePSDASK : public OutputDeviceInterface
{
public:
    OutputDevicePSDASK(CommonDeviceInterface *commonDevice) : OutputDeviceInterface(commonDevice)
    {
    }

    virtual void cont_buffer_compose(U16 wChannel, U32 dwUpdateCount, void *_conBuffer, void *_buffer);

    virtual bool supports_continuous_output() const;

    virtual void config(U16 d2k_configCtrl, U16 d2k_trgCtrl, U32 reTrgCnt, U32 DLY1Cnt, U32 DLY2Cnt, bool autoResetBuf);

    virtual U32 initial_memory_allocated_kb();

    /// Even though now the only PSDASK board supporting continuous mode is 6202
    /// (OutputDevice6202) most of it's functionality is defined here, so it will
    /// already be common in case some new card arrives.

    virtual U16 cont_buffer_setup(void *buffer, U32 writeCnt);

    virtual void async_check(bool &isStopped, U32 &accesCnt);

    virtual U32 async_clear();

    virtual void reset_buffers();

    virtual void configure_channel_range(U16 channel, U16 range_id);

    virtual void write_channel(U16 channel, U16 value);

    virtual void cont_write_multi_channels(U16 nchannels, U16 *chanBufIDs, U16 bufId, U32 writeCnt, U32 iterations, U32 CHUI, bool infinite, U16 syncMode);
};
