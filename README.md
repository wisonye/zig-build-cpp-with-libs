# C++ zig build demo

This demo shows how to use `build.zig` to compile a `C++` project. The project
has the following folder structure:

```bash
.
├── README.md
├── build               #`cmake` build folder
├── build.zig           # `Zig` build configuration file
├── clang_build.sh      # Single `clang` build command
├── CMakeLists.txt      # `cmake` configuration file
├── configure.sh        # Run `cmake` to configure
├── run.sh              # Use `cmake` to build and run
└── src
     ├── main.cpp       # `main` cpp, inclue `liba.so` and `lib.so` header files
     └── utils
         ├── a.cpp      # `liba.so` source file
         ├── a.h        # `liba.so` header file
         ├── b.cpp      # `libb.so` source file
         └── b.h        # `libb.so` header file
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

### Use `clang` command to build without `cmake`

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
clear && zig build run
```

</br>

