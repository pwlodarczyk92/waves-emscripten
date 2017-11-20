cmake_minimum_required(VERSION 3.8)
project(hello_wasm)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES src/regular/regular.c src/regular/regular.h src/board.c src/board.h src/image/image.c src/image/image.h src/patch/patch.c src/patch/patch.h src/regular/regular.c src/regular/regular.h src/patch/phasepatch.c src/patch/phasepatch.h src/main.c src/main.h src/table.c src/table.h src/image/palette.c src/image/palette.h)
add_library(hello_wasm ${SOURCE_FILES})
include_directories(/home/maxussd/emsdk/emscripten/1.37.22/system/include)