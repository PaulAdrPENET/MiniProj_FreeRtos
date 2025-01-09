//
// Created by paula on 09/01/2025.
//

#include "byte.h"

void Swap8(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

int htole(int u32){
    return u32;
}
int htobe(int u32){
    char *p = &u32;
    Swap8(&p[0],&p[3]);
    Swap8(&p[1],&p[2]);
}