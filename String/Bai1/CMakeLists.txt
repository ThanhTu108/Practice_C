cmake_minimum_required(VERSION 3.10)

# PROJECT_BIN = bai1
set(PROJECT_BIN "bai1")

project(${PROJECT_BIN})


# set path executable = ..../String/Bai1/bin
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# Set C and C++ standards
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(BUILD_SHARED_LIBS OFF)

# Add header fule
include_directories(${PROJECT_SOURCE_DIR}/)

add_executable(${PROJECT_BIN}
    ${PROJECT_SOURCE_DIR}/bai1.c
)

# Custom target to run the executable
add_custom_target(run COMMAND ${EXECUTABLE_OUTPUT_PATH}/${PROJECT_BIN} DEPENDS ${PROJECT_BIN})