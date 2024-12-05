
cmake_minimum_required(VERSION 3.10.2)
project (EventDistrib)

set(CMAKE_INSTALL_PREFIX "../EventDistrib")

########################################################
#####     OPTIONS                                  #####
########################################################
OPTION(WITH_RVM_PROCESS  "Enable RVM Process" ON)
OPTION(WITH_SVM_PROCESS  "Enable SVM Process" ON)
OPTION(WITH_DIAG_PROCESS "Enable DIAG Process" ON)

message(STATUS "Flag for using RVM : ${WITH_RVM_PROCESS}")
message(STATUS "Flag for using SVM : ${WITH_SVM_PROCESS}")
message(STATUS "Flag for using DIAG: ${WITH_DIAG_PROCESS}")

if(WITH_RVM_PROCESS)
    add_definitions(-DWITH_RVM_PROCESS)
endif(WITH_RVM_PROCESS)

if(WITH_SVM_PROCESS)
    add_definitions(-DWITH_SVM_PROCESS)
endif(WITH_SVM_PROCESS)

if(WITH_DIAG_PROCESS)
    add_definitions(-DWITH_DIAG_PROCESS)
endif(WITH_DIAG_PROCESS)

########################################################
#####     C / CXX / LD Flags Setting               #####
########################################################

# TODO: use -fpermissive for building cameracore
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O0 -std=c++14 -D_GLIBCXX_USE_NANOSLEEP -D_QNX_SOURCE -D_SUPPORT_QNX_")

########################################################
####    CCAMERASERVICE SOURCE BUILD                  ###
########################################################

set(RUNTIME_NAME EventDistrib)

#--- Source Files
set(SRC_DIR ..)

INCLUDE_DIRECTORIES(${SRC_DIR})

set(PRJ_SERVICE_SRCS
    ${SRC_DIR}/EventDistrib.cpp
    ${SRC_DIR}/RvmProcess.cpp
    ${SRC_DIR}/SvmProcess.cpp
    ${SRC_DIR}/DiagProcess.cpp
)

add_executable(${RUNTIME_NAME} ${PRJ_SERVICE_SRCS})

########################################################
####    INSTALL ARTIFACTS                            ###
########################################################
install(
    TARGETS ${RUNTIME_NAME}
    RUNTIME DESTINATION ..)

