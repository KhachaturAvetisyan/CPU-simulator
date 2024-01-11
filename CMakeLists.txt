cmake_minimum_required(VERSION 3.26)
project(CPU_simulator)

set(PROJECT_NAME "CPU_simulator")
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_BUILD_TYPE Release)

include_directories(${PROJECT_SOURCE_DIR}/headers)

file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES} main.cpp)

add_library(proj_src ${SOURCES})

message("Unit tests enabled!!")
enable_testing()
add_subdirectory(unit_tests)