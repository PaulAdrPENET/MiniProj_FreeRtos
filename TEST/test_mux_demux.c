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

int test_print_multiplex(void){
    //Creation of all four frames.
    Frame frames[NB_CHANNELS + 1];
    for (int i = 1; i <= NB_CHANNELS + 1; i++) {
        create_Frame(&frames[i-1], i);
    }

    //Display the 4 frames.
    printf("test_print_signal [BEGIN] \n");
    for (int i = 0; i < NB_CHANNELS + 1; i++) {
        Frame *frame = &frames[i];
        if (frame->data.channel <= NB_CHANNELS) {
            printf("Frame %d (Channel %d): Data = [%02X %02X %02X]\n",
                   i + 1,
                   frame->data.channel,
                   frame->data.value[0],
                   frame->data.value[1],
                   frame->data.value[2]);

        } else if (frame->state.channel == 4) {
            printf("Frame %d (Channel %d): State = [%02X]\n",
                   i + 1,
                   frame->state.channel,
                   frame->state.state);
        }
    }

    //Display the associated signal
    uint8_t signal[14];
    multiplex(frames, &signal);
    printf("Multiplexed Signal \n");
    printf("%02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X \n",signal[0], signal[1], signal[2], signal[3], signal[4], signal[5], signal[6], signal[7], signal[8], signal[9], signal[10], signal[11], signal[12], signal[13]);
    return 1;
}