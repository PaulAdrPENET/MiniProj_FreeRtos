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

int test_load_signal_from_queue(void){
    Frame frames[NB_CHANNELS + 1];
    uint8_t signal[14];
    Queue test_queue;

    test_queue.is_empty = 1;
    fill_queue(&test_queue);

    load_signal_from_queue(&test_queue, frames);
    int sum_signal_in_queue = 0;
    for (int i = 0; i < 14; i++) {
        sum_signal_in_queue += test_queue.signal[i];
    }
    if(sum_signal_in_queue == calculate_sum_frames(frames)){
        return 1;
    }
    else{
        printf("%d = %d \n", sum_signal_in_queue,calculate_sum_frames(frames));
        return 0;
    }
}