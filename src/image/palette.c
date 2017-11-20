//
// Created by maxussd on 20.11.17.
//

#include <stdlib.h>
#include <stdio.h>
#include "palette.h"
#include "../table.h"

inline int address(float value, int palsize, int start, int end) {
    float scaled = (value - start) * palsize / (end - start);
    if (scaled >= palsize)
        return palsize-1;
    else if (scaled <= 0)
        return 0;
    return (int)scaled;
}

Palette* make_palette(int size, int* colors) {
    Palette* result = malloc(sizeof(Palette));
    result->size = size;
    result->colors = colors;
    return result;
}

void free_palette(Palette* palette) {
    free(palette);
}

void draw_with_palette(Table* table, int* image, Palette* palette) {
    int xsize = table->xsize;
    int ysize = table->ysize;
    int size = xsize * ysize;
    int palsize = palette->size;
    int* colors = palette->colors;
    float* values = table->values;
    for (int i = 0; i < size; ++i)
        image[i] = colors[address(values[i], palsize, -1, 1)];
}