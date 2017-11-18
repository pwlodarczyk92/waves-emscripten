//
// Created by maxussd on 14.11.17.
//

#ifndef HELLO_WASM_REGULAR_H
#define HELLO_WASM_REGULAR_H

#include "../board.h"

typedef struct RegData {
    float acceleration;
    float damping;
} RegData;

Board* make_regular_board(int xsize, int ysize, float acceleration, float damping, float timestep);

#endif //HELLO_WASM_REGULAR_H
