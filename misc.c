//
// Created by paula on 15/01/2025.
//

#include "misc.h"

int calculate_sum_frames(Frame *frames){
    int sum_frames = 0;
    for (int i = 0; i < NB_CHANNELS + 1; i++) {
        Frame *frame = &frames[i];
        if (frame->data.channel <= NB_CHANNELS) {
            sum_frames += frame->data.channel;
            sum_frames += frame->data.value[0];
            sum_frames += frame->data.value[1];
            sum_frames += frame->data.value[2];

        } else if (frame->state.channel == 4) {
            sum_frames += frame->state.channel;
            sum_frames += frame->state.state;
        }
    }
    return sum_frames;
}

int calculate_sum_rx_frames(RX_Frame *frames){
    int sum_frames = 0;
    for (int i = 0; i < NB_CHANNELS + 1; i++) {
        RX_Frame *frame = &frames[i];
        if (frame->frame.data.channel <= NB_CHANNELS) {
            sum_frames += frame->frame.data.channel;
            sum_frames += frame->frame.data.value[0];
            sum_frames += frame->frame.data.value[1];
            sum_frames += frame->frame.data.value[2];

        } else if (frame->frame.state.channel == 4) {
            sum_frames += frame->frame.state.channel;
            sum_frames += frame->frame.state.state;
        }
    }
    return sum_frames;
}


int calculate_sum_signal(uint8_t *signal){
    int sum_signal_array = 0;
    for(int i = 0; i<14;i++){
        sum_signal_array += signal[i];
    }
    return sum_signal_array;
}