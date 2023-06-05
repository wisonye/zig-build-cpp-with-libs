#!/bin/sh

clang \
-pedantic-errors -Wall -std=gnu17 -g \
-I src/utils \
-L build \
-la -lb \
src/main.c -o build/c
