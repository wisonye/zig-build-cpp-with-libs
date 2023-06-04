# C++ zig build demo

This demo shows how to use `build.zig` to compile a `C++` project. It includes
everything you need to know when dealing with a `C++` project with `Zig`.

The project has the following folder structure:

```bash
.
├── README.md
├── build               #`cmake` build folder
├── build.zig           # `Zig` build configuration file
├── clang_build.sh      # Single `clang` build command
├── CMakeLists.txt      # `cmake` configuration file
├── configure.sh        # Configure `cmake`
├── run.sh              # Use `cmake` to build and run
└── src
     ├── main.cpp       # `main` cpp calls namespace functions in `liba.so` and `lib.so`
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
./clang_build.sh
```

</br>

After that, you can check it and run it like this:

```bash
LD_LIBRARY_PATH=./build ldd test
LD_LIBRARY_PATH=./build ./test
```

</br>

### Use `zig` to build the project

This only works once you build the project via `cmake`, as it doesn't build
`liba.so` and `lib.so` but just links to them!!!

```bash
zig build run
```

</br>

