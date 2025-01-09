//
// Created by paula on 09/01/2025.
//

#ifndef MINI_PROJET_BYTE_H
#define MINI_PROJET_BYTE_H

/*  Conversion le / be
int (htole_t)(int);
int (htobe_t)(int);

htole_t *htole = NULL;
htobe_t *htobe = NULL;
*/

void Swap8(char *a, char *b);

int htole(int u32);

int htobe(int u32);

#endif //MINI_PROJET_BYTE_H
