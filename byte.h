//
// Created by paula on 09/01/2025.
//

#ifndef MINI_PROJET_BYTE_H
#define MINI_PROJET_BYTE_H

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "trame.h"
#include <time.h>

/*  Conversion le / be
int (htole_t)(int);
int (htobe_t)(int);

htole_t *htole = NULL;
htobe_t *htobe = NULL;
*/

void Swap8(uint8_t *a,uint8_t *b);

int htole(int u32);

int htobe(int u32);

int rand8(void);

void invert_frame_bytes(Frame *frames);

#endif //MINI_PROJET_BYTE_H
