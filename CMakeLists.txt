cmake_minimum_required(VERSION 3.8)
project(EdisonNative)

set(CMAKE_BUILD_TYPE Release)

LIST(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_PREFIX}/cmake")
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(JNI REQUIRED)
include_directories(${JNI_INCLUDE_DIRS})

include(cmake/FindBluez.cmake)
#find_package (Bluez REQUIRED cmake/FindBluez.cmake)
include_directories(${BLUEZ_INCLUDE_DIRS})
link_directories(${BLUEZ_LIBRARIES})

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        com_homemods_relay_pi_bluetooth_BluetoothServerNativeImpl.cpp
        com_homemods_relay_pi_bluetooth_BluetoothServerSocketNativeImpl.cpp
        com_homemods_relay_pi_bluetooth_BluetoothSocketNativeImpl.cpp
        com_homemods_relay_pi_bluetooth_BluetoothClientNativeImpl.cpp
        com_homemods_relay_pi_bluetooth_BluetoothClientSocketNativeImpl.cpp bluetooth_helper.h)

add_library(EdisonNative SHARED ${SOURCE_FILES})
