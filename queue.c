//
// Created by paula on 15/01/2025.
//

#include "queue.h"

int fill_queue(Queue *queue){
    uint8_t signal[14];
    send_new_signal(signal);
    if (queue->is_empty) {
        memcpy(queue->signal, signal, sizeof(queue->signal));
        queue->is_empty = 0;
        return 1;
    } else {
        return 0;
    }
}

int load_signal_from_queue(Queue *queue, Frame *frames){
    if (queue->is_empty == 0) {
        parse_signal(frames, queue->signal);
        queue->is_empty = 1;
    } else {
        return 0;
    }
}


