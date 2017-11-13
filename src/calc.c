#include "calc.h"
#include <stdlib.h>
#include <emscripten/emscripten.h>
#include <stdint.h>

int makecol(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    return (a << 24) + (b << 16) + (g << 8) + r;
}

int* alloc(int size, uint8_t start) {
    int* result = malloc(sizeof(int) * size);
    for (int i = 0; i < size; ++i) {
        result[i] = makecol((uint8_t) (start + i), 0, 0, 255);
    }
    return result;
}