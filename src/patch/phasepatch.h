//
// Created by maxussd on 15.11.17.
//

#ifndef HELLO_WASM_PHASEPATCH_H
#define HELLO_WASM_PHASEPATCH_H

#include "../table.h"

void apply_phase_patch(Table* target, PhaseTable *patch, int xstart, int ystart, float factor, float phase);

#endif //HELLO_WASM_PHASEPATCH_H
