//
// Created by maxussd on 16.11.17.
//

#include <stdlib.h>
#include "table.h"
#include "board.h"

Table* make_table(int xsize, int ysize, float* values) {
    Table* result = malloc(sizeof(Table));
    result->xsize = xsize;
    result->ysize = ysize;
    result->values = values;
    return result;
}

PhaseTable* make_phase_table(int xsize, int ysize, float* values, float* shifts) {
    PhaseTable* result = malloc(sizeof(PhaseTable));
    result->xsize = xsize;
    result->ysize = ysize;
    result->values = values;
    result->shifts = shifts;
    return result;
}

void free_table(Table* table) {
    free(table);
}

void free_phase_table(PhaseTable* table) {
    free(table);
}

int inline idx(int xsize, int ysize, int x, int y) {
    return xsize * y + x;
}

float inline around(float* vals, int xs, int ys, int i) {
    return vals[i - 1] +
           vals[i + 1] +
           vals[i - xs] +
           vals[i + xs];
}

void normalize(Table* table) {
    int xsize = table->xsize;
    int ysize = table->ysize;
    float* values = table->values;

    float majorsum = 0;
    for (int y = 0; y < ysize; ++y) {
        float minorsum = 0;
        for (int x = 0; x < xsize; ++x) {
            minorsum += values[idx(xsize, ysize, x, y)];
        }
        majorsum += minorsum/xsize;
    }

    float mean = majorsum/ysize;
    for (int y = 0; y < ysize; ++y) {
        for (int x = 0; x < xsize; ++x) {
            values[idx(xsize, ysize, x, y)] -= mean;
        }
    }
}

void affine(Table* table, int x, int y, float a, float b) {
    int i = idx(table->xsize, table->ysize, x, y);
    table->values[i] *= a;
    table->values[i] += b;
}
