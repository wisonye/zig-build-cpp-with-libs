cmake_minimum_required(VERSION "3.22")

project("cpp_temp")

#
# Generate `compile_commands.json` for `Neovim` LSP needed
#
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

#
# Compiler flags
#
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_C_FLAGS "-pedantic-errors -std=gnu17")
set(CMAKE_CXX_FLAGS "-pedantic-errors -Wc++11-extensions -std=c++17")

#
# Find installed libraries as compilation dependencies
# https://cmake.org/cmake/help/latest/command/find_package.html
#
# find_package(raylib REQUIRED)

# -----------------------------------------------------------------------------
# Compile the particular source code as a static/dynamic library
#
# - static lib:  lib${LIBRARY_NAME}.a
# - dynamic lib: lib${LIBRARY_NAME}.so
#
# `add_library`: Adds a library target called <name> to be built from the source
#                files listed in the command invocation
#
# syntax: add_library(<name> [STATIC | SHARED | MODULE]
#           [EXCLUDE_FROM_ALL]
#           source1 [source2 ...])
#
# More details from here:
# https://cmake.org/cmake/help/v3.0/command/add_library.html?highlight=add_library
# -----------------------------------------------------------------------------
set(LIBRARY_A_NAME "a")
set(LIBRARY_A_SOURCE_FILE "src/utils/a.cpp")
set(LIBRARY_A_HEADER_FILE "src/utils/a.h")
add_library("${LIBRARY_A_NAME}" SHARED "${LIBRARY_A_SOURCE_FILE}")
#add_library("${UTILS_LIBRARY_NAME}" STATIC "${UTILS_LIBRARY_SOURCE_FILE}")

set(LIBRARY_B_NAME "b")
set(LIBRARY_B_SOURCE_FILE "src/utils/b.cpp")
set(LIBRARY_B_HEADER_FILE "src/utils/b.h")
add_library("${LIBRARY_B_NAME}" SHARED "${LIBRARY_B_SOURCE_FILE}")

include_directories("${CMAKE_SOURCE_DIR}/src/utils")

#
# Main exectuable
#
add_executable("${PROJECT_NAME}"
    "src/main.cpp")

#
# Link to library
#
target_link_libraries("${PROJECT_NAME}" "${LIBRARY_A_NAME}" "${LIBRARY_B_NAME}")

# target_compile_definitions("${PROJECT_NAME}" PRIVATE ENABLE_DEBUG_LOG)

#
# Debug log
#
message(">>> CMAKE_EXPORT_COMPILE_COMMANDS: ${CMAKE_EXPORT_COMPILE_COMMANDS}")
message(">>> CMAKE_SYSTEM_NAME: ${CMAKE_SYSTEM_NAME}")
message(">>> CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
message(">>> CMAKE_C_COMPILER: ${CMAKE_C_COMPILER}")
message(">>> CMAKE_C_FLAGS: ${CMAKE_C_FLAGS}")
message(">>> CMAKE_C_FLAGS_DEBUG: ${CMAKE_C_FLAGS_DEBUG}")
message(">>> CMAKE_C_FLAGS_RELEASE: ${CMAKE_C_FLAGS_RELEASE}")
message(">>> CMAKE_CXX_COMPILER: ${CMAKE_CXX_COMPILER}")
message(">>> CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")
message(">>> CMAKE_CXX_FLAGS_DEBUG: ${CMAKE_CXX_FLAGS_DEBUG}")
message(">>> CMAKE_CXX_FLAGS_RELEASE: ${CMAKE_CXX_FLAGS_RELEASE}")
