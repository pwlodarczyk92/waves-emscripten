//
// Created by maxussd on 13.11.17.
//

#include <stdlib.h>
#include <stdio.h>
#include "patch.h"
#include "board.h"

struct patch* make_patch(int xsize, int ysize, float* values) {
    struct patch* result = malloc(sizeof(struct patch));
    result->xsize = xsize;
    result->ysize = ysize;
    result->values = values;
    return result;
}

int max(int a, int b) {
    return a > b ? a : b;
}
int min(int a, int b) {
    return a < b ? a : b;
}

void apply(struct patch* target, struct patch *patch, int xstart, int ystart, float factor) {
    if (xstart >= target->xsize || ystart >= target->ysize)
        return;
    int xend = xstart + patch->xsize;
    int yend = ystart + patch->ysize;
    if (xend <= 0 || yend <= 0)
        return;

    float* tvalues = target->values;
    int txsize = target->xsize;
    int tysize = target->ysize;
    float* pvalues = patch->values;
    int pxsize = patch->xsize;
    int pysize = patch->ysize;

    int x0 = max(0, -xstart);
    int y0 = max(0, -ystart);
    int x1 = min(target->xsize - xstart, patch->xsize);
    int y1 = min(target->ysize - ystart, patch->ysize);
    for (int dx = x0; dx < x1; dx++) {
        for (int dy = y0; dy < y1; dy++) {
            tvalues[idx(txsize, tysize, dx + xstart, dy + ystart)] += factor * pvalues[idx(pxsize, pysize, dx, dy)];
        }
    }
}

struct patch* velocity_patch(struct board *board) {
    struct patch *vpatch = malloc(sizeof(struct patch));
    vpatch->xsize = board->xsize;
    vpatch->ysize = board->ysize;
    vpatch->values = board->velocity;
    return vpatch;
}

struct patch* deflection_patch(struct board *board) {
    struct patch *dpatch = malloc(sizeof(struct patch));
    dpatch->xsize = board->xsize;
    dpatch->ysize = board->ysize;
    dpatch->values = board->deflection;
    return dpatch;
}