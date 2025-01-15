//
// Created by paula on 09/01/2025.
//
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "trame.h"

#ifndef MINI_PROJET_MUX_DEMUX_H
#define MINI_PROJET_MUX_DEMUX_H

void generate_random_order(uint8_t *order);

uint8_t multiplex(Frame *frames, uint8_t *signal);

#endif //MINI_PROJET_MUX_DEMUX_H