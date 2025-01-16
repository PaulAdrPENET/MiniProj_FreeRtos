//
// Created by paula on 09/01/2025.
//

#ifndef MINI_PROJET_TRAME_H
#define MINI_PROJET_TRAME_H

#include <stdint.h>
#include <stdio.h>
//#include "byte.h"

#define NB_CHANNELS 3

typedef struct {
    //uint8_t type;
    union {
        struct {
            uint8_t channel;
            uint8_t value[3];
        } data;
        struct {
            uint8_t channel;
            uint8_t state;
        } state;
    };
} Frame;

typedef struct {
    Frame frame;
    uint32_t timestamp;
} RX_Frame;

void create_Frame(Frame * frame, uint8_t channel);

#endif //MINI_PROJET_TRAME_H