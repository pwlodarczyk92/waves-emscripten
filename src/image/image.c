//
// Created by maxussd on 13.11.17.
//

#include <stdint.h>
#include <stdlib.h>
#include "image.h"
#include "../board.h"

int makecol(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    return (a << 24) + (b << 16) + (g << 8) + r;
}

int* make_image(int xsize, int ysize) {
    int* result = malloc(sizeof(uint8_t) * xsize * ysize * 4);
    return result;
}

void free_image(int *image) {
    free(image);
}

uint8_t clamp(float value, float start, float end) {
    float scaled = 256 * (value - start) / (end - start);
    if (scaled <= 0)
        return 0;
    if (scaled >= 256)
        return 255;
    return (uint8_t)scaled;
}

void draw_table(Table *table, int *image) {
    int xsize = table->xsize;
    int ysize = table->ysize;
    int size = xsize * ysize;
    float* values = table->values;
    for (int i = 0; i < size; ++i) {
        uint8_t clamped = clamp(values[i], -1, 1);
        image[i] = makecol(clamped, clamped, clamped, 255);
    }
}