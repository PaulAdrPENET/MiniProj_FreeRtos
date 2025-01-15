//
// Created by paula on 09/01/2025.
//
#include <stdint.h>
#include <stdio.h>
#include "byte.h"

#ifndef MINI_PROJET_TRAME_H
#define MINI_PROJET_TRAME_H

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

void create_Frame(Frame * frame, uint8_t channel);

#endif //MINI_PROJET_TRAME_H
