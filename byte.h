//
// Created by paula on 09/01/2025.
//
#include <stdint.h>
#include <stdio.h>
#include <time.h>

#ifndef MINI_PROJET_BYTE_H
#define MINI_PROJET_BYTE_H

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

#endif //MINI_PROJET_BYTE_H
