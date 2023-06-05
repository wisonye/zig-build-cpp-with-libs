#!/bin/sh

clang++ \
-pedantic-errors -Wc++11-extensions -std=c++17 -g \
-I src/utils \
-L build \
-la -lb \
src/main.cpp -o build/cpp_2
