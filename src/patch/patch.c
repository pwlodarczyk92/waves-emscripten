//
// Created by maxussd on 13.11.17.
//

#include "patch.h"
#include "../board.h"
#include "../table.h"

int max(int a, int b) {
    return a > b ? a : b;
}
int min(int a, int b) {
    return a < b ? a : b;
}

void apply_patch(Table* target, Table *patch, int xstart, int ystart, float factor) {
    if (xstart >= target->xsize || ystart >= target->ysize)
        return;
    int xend = xstart + patch->xsize;
    int yend = ystart + patch->ysize;
    if (xend <= 0 || yend <= 0)
        return;

    int x0 = max(0, -xstart);
    int y0 = max(0, -ystart);
    int x1 = min(target->xsize - xstart, patch->xsize);
    int y1 = min(target->ysize - ystart, patch->ysize);


    int txsize = target->xsize;
    int tysize = target->ysize;
    int pxsize = patch->xsize;
    int pysize = patch->ysize;
    float* pvalues = patch->values;
    float* tvalues = target->values;
    for (int dx = x0; dx < x1; dx++) {
        for (int dy = y0; dy < y1; dy++) {
            tvalues[idx(txsize, tysize, dx + xstart, dy + ystart)] += factor * pvalues[idx(pxsize, pysize, dx, dy)];
        }
    }
}