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
    result->indices = malloc(sizeof(int) * xsize * ysize);
    float* defl = result->deflection;
    float* velo = result->velocity;
    int* indices = result->indices;
    for (int i = 0; i < xsize * ysize; ++i) {
        defl[i] = 0.0f;
        velo[i] = 0.0f;
    }

    int next = 0;
    for (int y = 1; y < ysize-1; ++y) {
        for (int x = 1; x < xsize-1; ++x) {
            int i = idx(xsize, ysize, x, y);
            indices[next] = i;
            next++;
        }
    }
    indices[next] = -1;

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
    int* indices = board->indices;

    float acc_factor = board->acceleration * board->timestep;
    float damp_factor = 1 - board->damping * board->timestep;

    int xs = board->xsize;
    int ys = board->ysize;

    int n = 0;
    int i = indices[n++];
    while(i >= 0) {
        float diff = around(defl, xs, ys, i) * 0.25f - defl[i];
        velo[i] += diff * acc_factor;
        velo[i] *= damp_factor;
        i = indices[n++];
    }
}

void increment_deflection(struct board *board) {
    float* defl = board->deflection;
    float* velo = board->velocity;
    int* indices = board->indices;

    int xs = board->xsize;
    int ys = board->ysize;
    float timestep = board->timestep;

    int n = 0;
    int i = indices[n++];
    while(i >= 0) {
        defl[i] += velo[i] * timestep;
        i = indices[n++];
    }
}

void increment(struct board *board) {
    increment_deflection(board);
    increment_velocity(board);
    board->time += board->timestep;
}