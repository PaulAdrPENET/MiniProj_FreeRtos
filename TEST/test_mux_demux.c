//
// Created by paula on 14/01/2025.
//

#include "test_mux_demux.h"

int test_generate_random_order(void) {
    uint8_t order[4];
    uint8_t occurrences[4] = {0};

    generate_random_order(order);

    // We check if the values are logical
    for(uint8_t i = 0; i <= 3; i++) {
        if (order[i] < 1 || order[i] > 4){
            return 0;
        }
        occurrences[order[i] - 1] += 1;
    }
    // We check if each value have only one occurence. 
    for(uint8_t i = 0; i <= 3; i++) {
        if (occurrences[i] != 1) {
            return 0;
        }
    }
    return 1;
}