//
// Created by paula on 09/01/2025.
//
#include "mux.h"

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
uint8_t multiplex(Frame *frames, uint8_t *signal){

    uint8_t order[4];
    generate_random_order(order);

    uint8_t array_index = 0;
    uint8_t channel = 0;

    for (uint8_t i = 0; i < 4; i++) {
        channel = order[i];
        if (channel <= NB_CHANNELS) { //Channel X, Y or Z
            signal[array_index++] = frames[channel - 1].data.channel;
            signal[array_index++] = frames[channel - 1].data.value[0];
            signal[array_index++] = frames[channel - 1].data.value[1];
            signal[array_index++] = frames[channel - 1].data.value[2];
        } else if (channel == 4) { //Channel 4
            signal[array_index++] = frames[3].state.channel;
            signal[array_index++] = frames[3].state.state;
        }
    }
}

uint8_t send_new_signal(uint8_t *signal){
    //Creation of all four frames.
    Frame frames[NB_CHANNELS + 1];
    for (int i = 1; i <= NB_CHANNELS + 1; i++) {
        create_Frame(&frames[i-1], i);
    }
    multiplex(frames, signal);
    return *signal;
}