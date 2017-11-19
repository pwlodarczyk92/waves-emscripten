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

uint8_t clamp(float value, float start, float end) {
    if (value < start)
        return 0;
    if (value >= end)
        return 255;
    return (uint8_t)((value - start) * 255.999 / (end - start));
}

void draw_table(Table *table, int *image) {
    for (int i = 0; i < table->xsize * table->ysize; ++i) {
        uint8_t clamped = clamp(table->values[i], -1, 1);
        image[i] = makecol(clamped, clamped, clamped, 255);
    }
}