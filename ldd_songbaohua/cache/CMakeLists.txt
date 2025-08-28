cmake_minimum_required(VERSION 3.10)
project(algorithm_service LANGUAGES C CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wno-attributes)

if(NOT DEFINED WUKONG_SDK_INCLUDE_DIRECTORIES_FOR_CLION)
    SET(STAGING_DIR /home/jia/work/app/staging_dir)
    SET(TOOLCHAINS_DIR ${STAGING_DIR}/toolchain-arm_cortex-a7+neon-vfpv4_gcc-11.2.0_uClibc_eabi/bin)

    SET(CMAKE_C_COMPILER ${TOOLCHAINS_DIR}/arm-openwrt-linux-gcc)
    SET(CMAKE_CXX_COMPILER ${TOOLCHAINS_DIR}/arm-openwrt-linux-g++)
    SET(CMAKE_STRIP ${TOOLCHAINS_DIR}/arm-openwrt-linux-strip)

    SET(SDK_DIR ${STAGING_DIR}/target-arm_cortex-a7+neon-vfpv4_uClibc_eabi)
    include_directories(${SDK_DIR}/usr/include)
    link_directories(${SDK_DIR}/usr/lib/)
endif()


add_executable(cache_test cache_test.cc)

INSTALL(TARGETS cache_test  RUNTIME DESTINATION bin)
