#include <stdlib.h>
#include "board.h"
#include "table.h"

Board* make_board(int xsize, int ysize, float timestep) {
    Board* result = malloc(sizeof(Board));
    result->xsize = xsize;
    result->ysize = ysize;
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

    return result;
}

void increment(Board* board) {
    board->incr_ptr(board);
    board->time += board->timestep;
}

void desctruct(Board* board) {
    board->desctruct(board);
    free(board->deflection);
    free(board->velocity);
    free(board);
}

void set_timestep(Board* board, float timestep) {
    board->timestep = timestep;
}

float get_time(Board* board) {
    return board->time;
}

Table* deflection_table(Board* board) {
    return make_table(board->xsize, board->ysize, board->deflection);
}

Table* velocity_table(Board* board) {
    return make_table(board->xsize, board->ysize, board->velocity);
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

