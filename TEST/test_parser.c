//
// Created by paula on 15/01/2025.
//

#include "test_parser.h"

int test_print_parse_signal(){
    Frame frames[NB_CHANNELS + 1];
    for (int i = 1; i <= NB_CHANNELS + 1; i++) {
        create_Frame(&frames[i-1], i);
    }

    //Display the 4 frames.
    printf("test_print_parse_signal [BEGIN] \n");
    printf("Initial frames : \n");
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

    parse_signal(frames, &signal);
    printf("Parsed frames : \n");
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
    return 1;
}

int test_sum_parse_signal(){
    Frame frames[NB_CHANNELS + 1];
    for (int i = 1; i <= NB_CHANNELS + 1; i++) {
        create_Frame(&frames[i-1], i);
    }
    int sum_signal_array = 0;

    uint8_t signal[14];
    multiplex(frames, &signal);
    for(int i = 0; i<14;i++){
        sum_signal_array += signal[i];
    }
    parse_signal(frames, &signal);

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
    if(sum_frames == sum_signal_array){
        //printf("%d = %d \n", sum_frames, sum_signal_array);
        return 1;
    }
    else{
        return 0;
    }
}