add_default_executable(hello-fmt hello-fmt.cc)
target_link_libraries(hello-fmt PRIVATE CONAN_PKG::fmt)

add_default_executable(hello-ut hello-ut.cc)
target_link_libraries(hello-ut PRIVATE CONAN_PKG::UT)
add_test(hello-ut hello-ut)
