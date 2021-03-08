cmake_minimum_required(VERSION 3.0.0)
project(AdlinkIODS VERSION 0.1.0)

add_executable(AdlinkIODS
            src/AdlDeviceFactorySingleton.cpp
            src/AdlinkBase.cpp
            src/BaseBehaviour.cpp
            src/AdlHelp.cpp
            src/AdlinkCommon.cpp
            src/CircularPosition.cpp
            src/tango_utils.cpp
            src/Utils.cpp
            ClassFactory.cpp
            ../AnalogDAQ/trunk/AnalogDAQClass.cpp
            ../AnalogDAQ/trunk/AnalogDAQStateMachine.cpp
            main.cpp
)

include_directories("${PROJECT_BINARY_DIR}"
                    ".",
                    "./",
                    "./include",
                    "./aio/",
                    "./dio/",
                    "./counter/"
                    "/homelocal/sicilia/src/adlink/adlink.d2k-dask/include",
                    "/homelocal/sicilia/src/adlink/adlink.wd-dask/include",
                    "/homelocal/sicilia/workspace/DigitalIO/DIO/include/",
                    "/usr/include",
                    "/usr/include/tango",
                    "/usr/local/include",
                    "../AnalogDAQ/trunk/include",
                    "../pci/include")




set(LIBRARIES tango log4tango omniORB4 omniDynamic4 omnithread	COS4 dl pthread omniConnectionMgmt4   rt gsl gslcblas)

find_library(ADLINK_PCI               pci_dask        HINTS /homelocal/sicilia/workspace/pci/lib)
find_library(ADLINK_PCI_DASK2k        pci_dask2k64    HINTS /homelocal/sicilia/workspace/adlink.d2k-dask/lib)
find_library(ADLINK_WD_DASK           wd_dask64       HINTS /homelocal/sicilia/workspace/adlink.wd-dask/lib_x86_64)

find_library(ADLINK_AIO_LIBRARY       AdlinkAIO       HINTS /homelocal/sicilia/workspace/AdlinkIODS/aio/build)
find_library(ADLINK_IOCounter_LIBRARY AdlinkIOCounter HINTS /homelocal/sicilia/workspace/AdlinkIODS/counter/build)
find_library(ADLINK_DIO_LIBRARY       AdlinkDIO       HINTS /homelocal/sicilia/workspace/AdlinkIODS/dio/build)
find_library(ADLINK_DigitalIO         tgclasses       HINTS /homelocal/sicilia/workspace/DigitalIO/DIO/lib)

target_link_libraries(AdlinkIODS PUBLIC 
                                        ${ADLINK_PCI} 
                                        ${ADLINK_PCI_DASK2k}
                                        ${ADLINK_WD_DASK} 
                                        ${ADLINK_AIO_LIBRARY} 
                                        ${ADLINK_IOCounter_LIBRARY} 
                                        ${ADLINK_DIO_LIBRARY} 
                                        ${ADLINK_DigitalIO}
                                        ${LIBRARIES})

link_directories("./aio/build",
                 "/homelocal/sicilia/workspace/AdlinkIODS/aio/build",
                 "./counter/build",
                 "./dio/build",
                 "/usr/lib",
                 "/homelocal/sicilia/workspace/DigitalIO/DIO/lib"
                 )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
