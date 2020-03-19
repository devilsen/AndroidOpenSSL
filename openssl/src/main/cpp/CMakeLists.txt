# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

file(GLOB SOURCE ${CMAKE_SOURCE_DIR}/*.cpp)

add_library(
        openssl
        SHARED
        ${SOURCE})

include_directories(include)

# 静态方式导入库
add_library(crypto STATIC IMPORTED)
add_library(ssl STATIC IMPORTED)

# 设置库路径
set_target_properties(crypto PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/../../../libs/${ANDROID_ABI}/libcrypto.a)
set_target_properties(ssl PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/../../../libs/${ANDROID_ABI}/libssl.a)


find_library(
        log-lib
        log)

target_link_libraries(
        openssl
        ssl
        crypto
        ${log-lib})