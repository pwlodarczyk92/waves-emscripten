//
// Created by maxussd on 14.11.17.
//

#include <stdlib.h>
#include "regular.h"
#include "../Board.h"

void increment_regular(Board *board);
void increment_deflection(Board *board);
void increment_velocity(Board *board);

float inline aroundl(float* vals, int xs, int ys, int i);
float inline aroundr(float* vals, int xs, int ys, int i);
float inline aroundd(float* vals, int xs, int ys, int i);
float inline aroundu(float* vals, int xs, int ys, int i);

Board* make_regular_board(int xsize, int ysize, float acceleration, float damping, float timestep) {

    Board* raw_board = make_board(xsize, ysize, timestep);
    RegData* data = malloc(sizeof(RegData));

    data->acceleration = acceleration;
    data->damping = damping;

    raw_board->data = data;
    raw_board->incr_ptr = increment_regular;

    return raw_board;
}

void increment_regular(Board *board) {
    increment_velocity(board);
    increment_deflection(board);
}

void increment_velocity(Board *board) {
    RegData* data = (RegData*)board->data;
    float* defl = board->deflection;
    float* velo = board->velocity;

    float acc_factor = data->acceleration * board->timestep;
    float damp_factor = 1 - data->damping * board->timestep;

    int xs = board->xsize;
    int ys = board->ysize;

    defl[idx(xs, ys, 0,    0)]    = 0.0f;
    defl[idx(xs, ys, 0,    ys-1)] = 0.0f;
    defl[idx(xs, ys, xs-1, 0)]    = 0.0f;
    defl[idx(xs, ys, xs-1, ys-1)] = 0.0f;

    for (int y = 1; y < ys-1; ++y) {
        for (int x = 1; x < xs-1; ++x) {
            int i = idx(xs, ys, x, y);
            float diff = around(defl, xs, ys, i) * 0.25f - defl[i];
            velo[i] += diff * acc_factor;
            velo[i] *= damp_factor;
        }
    }

    for (int y = 0; y < ys; ++y) {
        int il = idx(xs, ys, 0, y);
        float diffl = aroundl(defl, xs, ys, il) * 0.25f - defl[il] * 0.75f;
        velo[il] += diffl * acc_factor;
        velo[il] *= damp_factor;
        int ir = idx(xs, ys, xs-1, y);
        float diffr = aroundr(defl, xs, ys, ir) * 0.25f - defl[ir] * 0.75f;
        velo[ir] += diffr * acc_factor;
        velo[ir] *= damp_factor;
    }
    for (int x = 0; x < xs; ++x) {
        int id = idx(xs, ys, x, 0);
        float diffd = aroundd(defl, xs, ys, id) * 0.25f - defl[id] * 0.75f;
        velo[id] += diffd * acc_factor;
        velo[id] *= damp_factor;
        int iu = idx(xs, ys, x, ys-1);
        float diffu = aroundu(defl, xs, ys, iu) * 0.25f - defl[iu] * 0.75f;
        velo[iu] += diffu * acc_factor;
        velo[iu] *= damp_factor;
    }
}

void increment_deflection(Board *board) {
    float* defl = board->deflection;
    float* velo = board->velocity;

    int xs = board->xsize;
    int ys = board->ysize;
    float timestep = board->timestep;

    velo[idx(xs, ys, 0,    0)]    = 0.0f;
    velo[idx(xs, ys, 0,    ys-1)] = 0.0f;
    velo[idx(xs, ys, xs-1, 0)]    = 0.0f;
    velo[idx(xs, ys, xs-1, ys-1)] = 0.0f;

    for (int y = 0; y < ys; ++y) {
        for (int x = 0; x < xs; ++x) {
            int i = idx(xs, ys, x, y);
            defl[i] += velo[i] * timestep;
        }
    }
}

float inline aroundl(float* vals, int xs, int ys, int i) {
    return vals[i + 1] +
           vals[i - xs] +
           vals[i + xs];
}

float inline aroundr(float* vals, int xs, int ys, int i) {
    return vals[i - 1] +
           vals[i - xs] +
           vals[i + xs];
}

float inline aroundd(float* vals, int xs, int ys, int i) {
    return vals[i - 1] +
           vals[i + 1] +
           vals[i + xs];
}

float inline aroundu(float* vals, int xs, int ys, int i) {
    return vals[i - 1] +
           vals[i + 1] +
           vals[i - xs];
}
