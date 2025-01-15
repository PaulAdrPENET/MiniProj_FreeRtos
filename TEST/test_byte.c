//
// Created by paula on 10/01/2025.
//

#include "test_byte.h"

int test_swap8(void){
    uint8_t a = 1;
    uint8_t b = 2;
    Swap8(&a,&b);
    if(a == 2 && b == 1 ){
        return 1;
    }
    return 0;
}

int test_htobe(void){
    int u32_le = 0x12345678;
    int u32_be = 0x78563412;

    if (u32_be == htobe(u32_le)) {
        return 1;
    }
    return 0;
}

int test_rand8(void){
    for(int i = 0; i<1000; i++){
        int random_val = rand8();
        if(random_val < 0 || random_val > 255){
            return 0;
        }
    }
    return 1;
}

int test_invert_frame_bytes(void){
    Frame frames[4];
    Frame temp_frames[4];
    for (int i = 1; i <= NB_CHANNELS + 1; i++) {
        create_Frame(&frames[i-1], i);
    }
    memcpy(temp_frames, frames, sizeof(frames));
    invert_frame_bytes(&frames);
    if(temp_frames[0].data.value[0] == frames[0].data.value[2]
    && temp_frames[1].data.value[0] == frames[1].data.value[2]
    && temp_frames[2].data.value[0] == frames[2].data.value[2]
    && temp_frames[3].data.value[0] == frames[3].data.value[2]
    ){
        return 1;
    }
    else{
        return 0;
    }
}