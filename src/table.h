//
// Created by maxussd on 16.11.17.
//

#ifndef HELLO_WASM_TABLE_H
#define HELLO_WASM_TABLE_H

typedef struct Table {
    int xsize;
    int ysize;
    float* values;
} Table;

typedef struct PhaseTable {
    int xsize;
    int ysize;
    float* values;
    float* shifts;
} PhaseTable;

Table* make_table(int xsize, int ysize, float* values);
PhaseTable* make_phase_table(int xsize, int ysize, float* values, float* shifts);
void free_table(Table* table);
void free_phase_table(PhaseTable* table);

#endif //HELLO_WASM_TABLE_H
