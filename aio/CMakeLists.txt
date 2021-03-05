cmake_minimum_required(VERSION 3.0.0)
project(AdlinkAIO VERSION 0.1.0)

add_library(AdlinkAIO 
    AdlinkAIOClass.cpp
    AdlinkAIOStateMachine.cpp
    InputBehaviour.cpp
    InputDeviceD2K.cpp 
    MemAttrWriteCheck.cpp
    OutputDeviceInterface.cpp 
    StatsSettings.cpp
    AdlinkAIO.cpp       
    AdlinkDeviceThread.cpp     
    InputBuffer.cpp     
    InputDevicePSDASK.cpp  
    OutputBehaviour.cpp    
    StatsCalculator.cpp
    OutputDevicePSDASK.cpp
    OutputDevice6202.cpp
)

target_compile_definitions(AdlinkAIO PUBLIC _RSUNE_ENABLE_SHAREDBUFFER_RECORD_TIME )

target_include_directories(AdlinkAIO PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           ".",
                           "..",
                            "../include",
                            "./",
                            "./aio/",
                            "/homelocal/sicilia/src/adlink/adlink.d2k-dask/include",
                            "/homelocal/sicilia/src/adlink/adlink.wd-dask/include",
                            "/usr/include",
                            "/usr/include/tango",
                            "../../AnalogDAQ/trunk/",
                            "../../pci/include"
                           )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
