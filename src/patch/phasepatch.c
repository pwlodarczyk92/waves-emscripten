//
// Created by maxussd on 15.11.17.
//

#include <math.h>
#include "phasepatch.h"
#include "patch.h"

void apply_phase_patch(Table* target, PhaseTable *patch, int xstart, int ystart, float factor, float phase) {

    if (xstart >= target->xsize || ystart >= target->ysize)
        return;
    int xend = xstart + patch->xsize;
    int yend = ystart + patch->ysize;
    if (xend <= 0 || yend <= 0)
        return;

    int txsize = target->xsize;
    int tysize = target->ysize;
    int pxsize = patch->xsize;
    int pysize = patch->ysize;

    int x0 = max(0, -xstart);
    int y0 = max(0, -ystart);
    int x1 = min(target->xsize - xstart, patch->xsize);
    int y1 = min(target->ysize - ystart, patch->ysize);
    float* tvalues = target->values;
    float* pvalues = patch->values;
    float* pshifts = patch->shifts;
    for (int dx = x0; dx < x1; dx++) {
        for (int dy = y0; dy < y1; dy++) {
            int pidx = idx(pxsize, pysize, dx, dy);
            int tidx = idx(txsize, tysize, dx + xstart, dy + ystart);
            float shift = pshifts[pidx];
            float value = pvalues[pidx];
            tvalues[tidx] += factor * value * sinf(shift + phase);
        }
    }
}