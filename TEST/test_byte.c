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

}
