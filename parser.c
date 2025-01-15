//
// Created by paula on 09/01/2025.
//

#include "parser.h"

void parse_signal(Frame * frame, uint8_t *signal){
    uint8_t current_channel = 0;
    for(int i = 0; i <= 13;i++){
        current_channel = signal[i];
        if(current_channel <= NB_CHANNELS) {
            frame[current_channel - 1].data.channel = current_channel;
            i++;
            frame[current_channel - 1].data.value[0] = signal[i];
            i++;
            frame[current_channel - 1].data.value[1] = signal[i];
            i++;
            frame[current_channel - 1].data.value[2] = signal[i];
        } else if (current_channel == 4) {
            frame[3].state.channel = current_channel;
            i++;
            frame[3].state.state = signal[i];
        }
    }
}