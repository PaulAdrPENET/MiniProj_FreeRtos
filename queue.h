//
// Created by paula on 15/01/2025.
//
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "trame.h"
#include "mux.h"
#include "parser.h"

#ifndef MINI_PROJET_QUEUE_H
#define MINI_PROJET_QUEUE_H


typedef struct {
    uint8_t signal[14];
    uint8_t is_empty;
} Queue;

int fill_queue(Queue *queue);

#endif //MINI_PROJET_QUEUE_H
