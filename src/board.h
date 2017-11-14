//
// Created by maxussd on 13.11.17.
//

#ifndef HELLO_WASM_BOARD_H
#define HELLO_WASM_BOARD_H

struct board {
    int xsize;
    int ysize;
    float acceleration;
    float damping;
    float timestep;
    float time;
    float* deflection;
    float* velocity;
    int* indices;
};

struct board* make_board(int xsize, int ysize, float acceleration, float damping, float timestep);

int idx(int xsize, int ysize, int x, int y);

float around(float* vals, int xs, int ys, int i);

void increment_velocity(struct board *board);

void increment_deflection(struct board *board);

void increment(struct board *board);

#endif //HELLO_WASM_BOARD_H
