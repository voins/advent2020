add_default_executable(day01 day01.cc)
target_compile_definitions(day01 PRIVATE
    INPUT_FILE="${CMAKE_CURRENT_SOURCE_DIR}/input.txt")
target_link_libraries(day01 PRIVATE CONAN_PKG::UT CONAN_PKG::fmt)
add_test(day01 day01)

add_default_executable(day01-test day01-test.cc)
target_link_libraries(day01-test PRIVATE CONAN_PKG::UT)
add_test(day01-test day01-test)
