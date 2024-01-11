# install conan libs
message(STATUS "Installing conan libs")
execute_process(COMMAND conan install ${PROJECT_SOURCE_DIR}/conanfile.txt --output-folder=${PROJECT_BINARY_DIR} --build=missing)
include(${PROJECT_BINARY_DIR}/conan_toolchain.cmake)

find_package(GTest REQUIRED)

file(GLOB SRCS
        "${PROJECT_SOURCE_DIR}/unit_tests/*.cpp"
)


include_directories(${GTest_INCLUDE_DIRS})

message(STATUS "SRCS: ${SRCS}")

add_executable(tests ${SRCS})

target_link_libraries(tests
        PRIVATE

        pthread

        gtest::gtest
        GTest::gtest
        GTest::gtest_main
        GTest::gmock
        GTest::gmock_main

        proj_src
)

include(GoogleTest)
gtest_discover_tests(tests)