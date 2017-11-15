//
// Created by maxussd on 13.11.17.
//

#ifndef HELLO_WASM_BOARD_H
#define HELLO_WASM_BOARD_H

typedef struct Board {
    int xsize;
    int ysize;
    float timestep;

    float *deflection;
    float *velocity;

    void *data;
    void (*incr_ptr)(struct Board*);

} Board;

Board* make_board(int xsize, int ysize, float timestep);

int idx(int xsize, int ysize, int x, int y);

float around(float* vals, int xs, int ys, int i);

void increment(Board *board);

#endif //HELLO_WASM_BOARD_H
