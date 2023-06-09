# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(blinky)

# set(CMAKE_CXX_STANDARD_LIBRARIES "-lc++ -lc -lm -lgcc -lnosys")

set(SRC_DIR "src")

set(INLCUDE_DIRS
    "${SRC_DIR}/common"
    "${SRC_DIR}/bsp"
    "${SRC_DIR}/led"
    "${SRC_DIR}/task"
)

set(SRC_FILES
    "${SRC_DIR}/main.cpp"
    "${SRC_DIR}/led/led.cpp"
    "${SRC_DIR}/task/led_array.cpp"
    "${SRC_DIR}/common/print.cpp"
    "${SRC_DIR}/bsp/instances.cpp"
    "${SRC_DIR}/bsp/dt_instances.cpp"
)

target_include_directories(app PRIVATE ${INLCUDE_DIRS})
target_sources(app PRIVATE ${SRC_FILES})
