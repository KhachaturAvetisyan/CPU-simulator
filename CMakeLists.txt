cmake_minimum_required(VERSION 3.26)
project(CPU_simulate)

set(PROJECT_NAME "CPU_simulate")
set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/headers)

file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

