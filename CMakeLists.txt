# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(blinky)


set(SRC_DIR "src")

set(INLCUDE_DIRS
    "${SRC_DIR}/common"
    "${SRC_DIR}/bsp"
    "${SRC_DIR}/led")

target_include_directories(app PRIVATE ${INLCUDE_DIRS})
target_sources(app PRIVATE src/main.cpp)
