#include <stdlib.h>
#include "board.h"

struct board* make_board(int xsize, int ysize, float acceleration, float damping, float timestep) {
    struct board* result = malloc(sizeof(struct board));
    result->xsize = xsize;
    result->ysize = ysize;
    result->acceleration = acceleration;
    result->damping = damping;
    result->timestep = timestep;
    result->time = 0;
    result->deflection = malloc(sizeof(float) * xsize * ysize);
    result->velocity = malloc(sizeof(float) * xsize * ysize);
    float* defl = result->deflection;
    float* velo = result->velocity;
    for (int i = 0; i < xsize * ysize; ++i) {
        defl[i] = 0.0f;
        velo[i] = 0.0f;
    }
    defl[idx(xsize, ysize, 1, 1)] = 1;
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

void increment_velocity(struct board *board) {
    float* defl = board->deflection;
    float* velo = board->velocity;

    float acc_factor = board->acceleration * board->timestep;
    float damp_factor = 1 - board->damping * board->timestep;

    int xs = board->xsize;
    int ys = board->ysize;
    for (int y = 1; y < ys-1; ++y) {
        for (int x = 1; x < xs-1; ++x) {
            int i = idx(xs, ys, x, y);
            float diff = around(defl, xs, ys, i) * 0.25f - defl[i];
            velo[i] += diff * acc_factor;
            velo[i] *= damp_factor;
        }
    }
}

void increment_deflection(struct board *board) {
    float* defl = board->deflection;
    float* velo = board->velocity;
    int xs = board->xsize;
    int ys = board->ysize;
    float timestep = board->timestep;

    for (int y = 1; y < ys-1; ++y) {
        for (int x = 1; x < xs-1; ++x) {
            int i = idx(xs, ys, x, y);
            defl[i] += velo[i] * timestep;
        }
    }
}

void increment(struct board *board) {
    increment_deflection(board);
    increment_velocity(board);
    board->time += board->timestep;
}