//
// Created by maxussd on 13.11.17.
//
#ifndef HELLO_WASM_PATCH_H
#define HELLO_WASM_PATCH_H
#import "../board.h"
#import "../table.h"

int max(int a, int b);
int min(int a, int b);
void apply_patch(Table* target, Table *patch, int xstart, int ystart, float factor);

#endif //HELLO_WASM_PATCH_H
