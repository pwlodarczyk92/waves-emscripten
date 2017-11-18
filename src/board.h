//
// Created by maxussd on 13.11.17.
//

#ifndef HELLO_WASM_BOARD_H
#define HELLO_WASM_BOARD_H

#include "table.h"

typedef struct Board {
    int xsize;
    int ysize;
    float timestep;
    float time;

    float *deflection;
    float *velocity;

    void *data;
    void (*incr_ptr)(struct Board*);
    void (*desctruct)(struct Board*);
} Board;

Board* make_board(int xsize, int ysize, float timestep);
void increment(Board *board);
void destruct(Board *board);

Table* deflection_table(Board* board);
Table* velocity_table(Board* board);

int idx(int xsize, int ysize, int x, int y);
float around(float* vals, int xs, int ys, int i);


#endif //HELLO_WASM_BOARD_H
