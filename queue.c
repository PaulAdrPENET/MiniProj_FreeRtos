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

int load_signal_from_queue(Queue *queue, RX_Frame *rx_frames){
    if (queue->is_empty == 0) {
        Frame frames[4];
        parse_signal(frames, queue->signal);
        queue->is_empty = 1;

        rx_frames[0].frame.data.channel = frames[0].data.channel;
        rx_frames[0].frame.data.value[0] = frames[0].data.value[0];
        rx_frames[0].frame.data.value[1] = frames[0].data.value[1];
        rx_frames[0].frame.data.value[2] = frames[0].data.value[2];

        rx_frames[1].frame.data.channel = frames[1].data.channel;
        rx_frames[1].frame.data.value[0] = frames[1].data.value[0];
        rx_frames[1].frame.data.value[1] = frames[1].data.value[1];
        rx_frames[1].frame.data.value[2] = frames[1].data.value[2];

        rx_frames[2].frame.data.channel = frames[2].data.channel;
        rx_frames[2].frame.data.value[0] = frames[2].data.value[0];
        rx_frames[2].frame.data.value[1] = frames[2].data.value[1];
        rx_frames[2].frame.data.value[2] = frames[2].data.value[2];

        rx_frames[3].frame.state.channel = frames[3].state.channel;
        rx_frames[3].frame.state.state = frames[3].state.state;
        
        rx_frames[0].timestamp = (uint32_t)time(NULL);
        rx_frames[1].timestamp = (uint32_t)time(NULL);
        rx_frames[2].timestamp = (uint32_t)time(NULL);
        rx_frames[3].timestamp = (uint32_t)time(NULL);
    } else {
        return 0;
    }
}