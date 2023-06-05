# C++ zig build demo

This demo shows how to use `build.zig` to compile a `C++` project. It includes
everything you need to know when dealing with a `C++` project with `Zig`.

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
     └── utils          # Lib `a` and `b`
         ├── a.cpp
         ├── a.h
         ├── b.cpp
         └── b.h
```

</br>

`CMake` builds the `liba.so` and `lib.so` first, then builds the `cpp_temp`
and links it to the `build/liba.so`  and `build/libb.so`.

### Configure `cmake` and build

```bash
./configure.sh
./run.sh
```

</br>

### Use `clang++` to build without `cmake`

This only works once you build the project via `cmake`, as it doesn't build
`liba.so` and `lib.so` but just links to them!!!

```bash
./build_cpp.sh
```

</br>

After that, you can check it and run it like this:

```bash
LD_LIBRARY_PATH=./build ldd build/cpp_2
LD_LIBRARY_PATH=./build ./build/cpp_2
```

</br>

### Use `zig` to build the project

This only works once you build the project via `cmake`, as it doesn't build
`liba.so` and `lib.so` but just links to them!!!

```bash
# Run CPP binary (pure C++ without zig)
zig build run-cpp

# Run ZIG binary (call C++ in zig)
zig build run-zig
```

</br>

