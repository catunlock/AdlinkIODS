cmake_minimum_required(VERSION 3.0.0)
project(AdlinkDIO VERSION 0.1.0)

add_library(AdlinkDIO
            AdlinkDIOClass.cpp 
            AdlinkDIO.cpp
            AdlinkDIOStateMachine.cpp
            ClassFactory.cpp
)


set(LIBRARIES tango log4tango omniORB4 omniDynamic4 omnithread	COS4 dl pthread omniConnectionMgmt4 pci_dask2k64 wd_dask64 rt tgclasses)
target_link_libraries(AdlinkDIO ${LIBRARIES})

include_directories("${PROJECT_BINARY_DIR}"
                    ".",
                    "..",
                    "../include",
                    "./",
                    "./aio/",
                    "/homelocal/sicilia/src/adlink/adlink.d2k-dask/include",
                    "/homelocal/sicilia/src/adlink/adlink.wd-dask/include",
                    "/homelocal/sicilia/workspace/DigitalIO/DIO/include/",
                    "/usr/include",
                    "/usr/include/tango",
                    "../../AnalogDAQ/trunk/",
                    "../../pci/include")

link_directories()

link_directories(
    "/usr/lib",
    "/homelocal/sicilia/workspace/DigitalIO/DIO/lib"
                )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
