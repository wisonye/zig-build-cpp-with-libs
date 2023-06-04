#!/bin/sh

#
# Remove everything exists
#
rm -rf build

#
# Run cmake to generate all files
#
cmake -S ./ -B ./build
