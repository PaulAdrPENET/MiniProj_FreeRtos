//
// Created by paula on 09/01/2025.
//

#include "test_signal.h"

int test_rand8(void){
    for(int i = 0; i<1000; i++){
        int random_val = rand8();
        if(random_val < 0 || random_val > 255){
            return 0;
        }
    }
    return 1;
}