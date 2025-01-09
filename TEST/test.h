//
// Created by paula on 09/01/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef MINI_PROJET_TEST_H
#define MINI_PROJET_TEST_H

#define DECL_TEST(test) {&test,#test}
#define LAST_TEST {NULL,NULL}

typedef int(test_func_t)(void);

typedef struct test_s{
    test_func_t *call;
    const char *name;
} test_t;

void test_all(test_t * test);


#endif //MINI_PROJET_TEST_H
