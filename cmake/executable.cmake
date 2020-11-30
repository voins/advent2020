function(add_default_executable NAME)
    add_executable(${NAME} ${ARGN})
    target_compile_features(${NAME} PRIVATE cxx_std_17)
    target_compile_options(${NAME} PRIVATE
        -Weverything
        -Werror
        -pedantic
        -pedantic-errors
        -Wno-c++98-compat
        -Wno-c++98-compat-pedantic
        -Wno-c99-extensions)
endfunction()
