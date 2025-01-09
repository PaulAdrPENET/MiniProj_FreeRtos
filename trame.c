//
// Created by paula on 09/01/2025.
//

#include "trame.h"

void create_Frame(Frame * frame, uint8_t channel){
    if(channel <= NB_CHANNELS){
        frame->data.channel = channel;
        frame->data.value[0] = rand8();
        frame->data.value[1] = rand8();
        frame->data.value[3] = rand8();
    } else if(channel == 4){
        frame->state.channel = channel;
        frame->state.state = 0x00;
    } else {
        printf("PARAMETER_ERROR");
    }
}