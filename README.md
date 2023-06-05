# C++ zig build demo

This demo shows how to use `build.zig` to compile a `C++` project and call `C++`
lib function in `Zig`. It includes everything you need to know about when dealing
with a `C++` project with `Zig`.

The project has the following folder structure:

```bash
.
├── README.md
├── build               #`cmake` build folder
├── build.zig           # `Zig` build configuration file
├── CMakeLists.txt      # `cmake` configuration file
├── configure.sh        # Configure `cmake`
├── run.sh              # Build `main.cpp` with `cmake` and run
├── build_cpp.sh        # Build `main.cpp` with `clang++`
├── build_c.sh          # Build `main.c` with `clang`
└── src
     ├── main.cpp       # `C++` calls namespace functions in `liba.so` and `lib.so`
     ├── main.c         # `C` calls namespace functions in `liba.so` and `lib.so`
     ├── main.zig       # `Zig` calls namespace functions in `liba.so` and `lib.so`
     └── utils          # Lib `a` and `b`
         ├── a.cpp
         ├── a.h
         ├── b.cpp
         └── b.h
```

</br>

### Use `cmake` to build and run

`cmake` builds the `build/liba.so` and `build/lib.so` first, then builds the
`./build/cpp` and links it to the `build/liba.so`  and `build/libb.so`.

```bash
./configure.sh

./run.sh
# >>> Simple zig build CPP demo.
# >>> [ A - Result ] {
# {
#          invisible_value: 28
#          is_success: true
# }
# >>> A::Result destroyed.
# >>> [ B - Result ]
# {
#          invisible_float: 88.456
# }
# >>> B::Result destroye
```

</br>

### Use `clang++` to build and run

This only works once you build the project via `cmake`, as it doesn't build
`liba.so` and `lib.so` but just links to them!!!

```bash
./build_cpp.sh && LD_LIBRARY_PATH=./build ./build/cpp_2
# >>> Simple zig build CPP demo.
# >>> [ A - Result ] {
# {
#          invisible_value: 28
#          is_success: true
# }
# >>> A::Result destroyed.
# >>> [ B - Result ]
# {
#          invisible_float: 88.456
# }
# >>> B::Result destroye
```

</br>

### Call `C++` lib function in `C`

This only works once you build the project via `cmake`, as it doesn't build
`liba.so` and `lib.so` but just links to them!!!

```bash
 ./build_c.sh && LD_LIBRARY_PATH=./build build/c

# >>> Calling C++ lib function in C:)
#
# >>> a_result value: 38
# >>> a_result is_success: true
# >>> [ A - Result ] {
# {
#          invisible_value: 38
#          is_success: true
# }
# >>> A::Result destroyed.
#
# >>> b_result value: 123.789
# >>> [ B - Result ]
# {
#          invisible_float: 123.789
# }
# >>> B::Result destroyed.
```

</br>

### Use `zig` to build the project

This only works once you build the project via `cmake`, as it doesn't build
`liba.so` and `lib.so` but just links to them!!!

- Build and run C++ binary (`zig-out/bin/cpp_binary`)

    ```bash
    zig build run-cpp

    # >>> Simple zig build CPP demo.
    # >>> [ A - Result ] {
    # {
    #          invisible_value: 28
    #          is_success: true
    # }
    # >>> A::Result destroyed.
    # >>> [ B - Result ]
    # {
    #          invisible_float: 88.456
    # }
    # >>> B::Result destroyed.
    ```

    </br>

- Build and run zig binary (`zig-out/bin/zig_binary`)

    ```bash
    zig build run-zig

    # >>> Calling C++ lib function in Zig:)
    #
    # >>> a_result value: 999
    # >>> a_result is_success: true
    # >>> [ A - Result ] {
    # {
    #          invisible_value: 999
    #          is_success: true
    # }
    # >>> A::Result destroyed.
    #
    # >>> b_result value: 55.456>>> [ B - Result ]
    # {
    #          invisible_float: 55.456
    # }
    # >>> B::Result destroyed.
    ```

    </br>

