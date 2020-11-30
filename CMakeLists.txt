cmake_minimum_required(VERSION 3.18)
include(cmake/local)
project(advent2020 CXX)

conan_cmake_run(REQUIRES
        fmt/7.1.2
        UT/latest
    BASIC_SETUP CMAKE_TARGETS NO_OUTPUT_DIRS
    BUILD missing)

enable_testing()
add_subdirectory(src)
