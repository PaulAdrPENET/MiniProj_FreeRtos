//
// Created by paula on 09/01/2025.
//
#include "mux_demux.h"

void generate_random_order(uint8_t *order) {
    for (uint8_t i = 0; i < 4; i++) {
        order[i] = i + 1;
    }
    // Knuth algorithme, (Fisher-Yates Shuffle)
    for (uint8_t i = 3; i > 0; i--) {
        uint8_t j = rand() % (i + 1);
        uint8_t temp = order[i];
        order[i] = order[j];
        order[j] = temp;
    }
    //printf("%d %d %d %d\n",order[0], order[1], order[2], order[3]);
}

//Multiplexage

//Demultiplexage