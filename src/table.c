//
// Created by maxussd on 16.11.17.
//

#include <stdlib.h>
#include "table.h"
#include "board.h"

Table* make_table(int xsize, int ysize, float* values) {
    Table* result = malloc(sizeof(Table));
    result->xsize = xsize;
    result->ysize = ysize;
    result->values = values;
    return result;
}

PhaseTable* make_phase_table(int xsize, int ysize, float* values, float* shifts) {
    PhaseTable* result = malloc(sizeof(PhaseTable));
    result->xsize = xsize;
    result->ysize = ysize;
    result->values = values;
    result->shifts = shifts;
    return result;
}

void free_table(Table* table) {
    free(table);
}
void free_phase_table(PhaseTable* table) {
    free(table);
}