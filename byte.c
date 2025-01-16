//
// Created by paula on 09/01/2025.
//

#include "byte.h"

void Swap8(uint8_t *a, uint8_t *b) {
    uint8_t temp = *a;
    *a = *b;
    *b = temp;
}

int htole(int u32){
    return u32;
}

int htobe(int u32){
    uint32_t *p = &u32;
    Swap8(&p[0],&p[3]);
    Swap8(&p[1],&p[2]);
    return u32;
}

int rand8(void){
    return rand()%256;
}

void invert_frame_bytes(Frame *frames){
    for (int i = 0; i < NB_CHANNELS; i++) {
        Swap8(&frames[i].data.value[0],&frames[i].data.value[2]);
    }
}
