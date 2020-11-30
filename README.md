https://adventofcode.com/2020 is almost here. Let's have some fun.

---

Use the standard procedure to compile and run

    cd build 
    cmake . -DCMAKE_BUILD_TYPE=Debug
    cmake --build .

    ctest -V

---

* UT is not in any conan repository known to me. I have it in my conan cache and
I've created it using the standard `conan create .` in a fresh checkout of [boost::ut](https://github.com/boost-ext/ut) with one simple change: I've deleted `'compiler'` setting from `conanfile.py`.

* `cmake/conan.cmake` can be updated by downloading a fresh version from
[cmake-conan](https://github.com/conan-io/cmake-conan/releases), once there is
a new release available.

* [{fmt}](https://github.com/fmtlib/fmt) is here for a quick link if I need to
lookup the docs

---

* The code is structured by days.
* I suspect there will be some common parts as well.
* Compiler warnings are tuned to my liking.
