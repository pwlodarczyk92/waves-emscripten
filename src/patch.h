//
// Created by maxussd on 13.11.17.
//
#ifndef HELLO_WASM_PATCH_H
#define HELLO_WASM_PATCH_H
#import "Board.h"

typedef struct Patch {
    int xsize;
    int ysize;
    float* values;
} Patch;

#endif //HELLO_WASM_PATCH_H
