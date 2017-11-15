#include <stdlib.h>
#include "board.h"
#include "regular/regular.h"

Board* make_board(int xsize, int ysize, float timestep) {
    Board* result = malloc(sizeof(Board));
    result->xsize = xsize;
    result->ysize = ysize;
    result->timestep = timestep;
    result->deflection = malloc(sizeof(float) * xsize * ysize);
    result->velocity = malloc(sizeof(float) * xsize * ysize);

    float* defl = result->deflection;
    float* velo = result->velocity;

    for (int i = 0; i < xsize * ysize; ++i) {
        defl[i] = 0.0f;
        velo[i] = 0.0f;
    }

    return result;
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

void increment(Board* board) {
    increment_regular(board);
}