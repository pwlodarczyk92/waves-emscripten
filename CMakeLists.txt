cmake_minimum_required(VERSION 3.8)
project(hello_wasm)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES src/Board.c src/Board.h src/image.c src/image.h src/patch.c src/patch.h src/regular/regular.c src/regular/regular.h)
add_library(hello_wasm ${SOURCE_FILES})
include_directories(/home/maxussd/emsdk/emscripten/1.37.22/system/include)