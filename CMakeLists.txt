cmake_minimum_required(VERSION 3.8)
project(hello_wasm)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES src/main.c src/main.h src/calc.c src/calc.h src/board.c src/board.h)
add_library(hello_wasm ${SOURCE_FILES})
include_directories(/home/maxussd/emsdk/emscripten/1.37.22/system/include)