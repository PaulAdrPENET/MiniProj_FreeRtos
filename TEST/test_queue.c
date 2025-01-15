//
// Created by paula on 15/01/2025.
//

#include "test_queue.h"

int test_fill_queue(void){
    Queue test_queue;
    test_queue.is_empty = 1;
    fill_queue(&test_queue);
    if(test_queue.is_empty == 0 && calculate_sum_signal(test_queue.signal) != 0){
        return 1;
    }
    else{
        return 0;
    }
}

int test_print_queue_content(void){
    printf("test_print_queue_content [BEGIN] \n");
    Queue test_queue;
    test_queue.is_empty = 1;
    fill_queue(&test_queue);
    for (int i = 0; i < 14; i++) {
        printf("%02X ", test_queue.signal[i]);
    }
    printf("\n");
    printf("Is_empty ? : %d \n", test_queue.is_empty);
    return 1;
}
