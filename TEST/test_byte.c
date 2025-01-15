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