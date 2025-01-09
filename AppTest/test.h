#ifndef TEST_LIB_H
#define TEST_LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define DECL_TEST(test) {&test,#test}
#define LAST_TEST {NULL,NULL}

typedef int(test_func_t)(void);

typedef struct test_s{
    test_func_t *call;
    const char *name;
} test_t;

void test_all(test_t * test);

//const char* strbool(int v);

int test_1(void);
int test_2(void);

int test_random_data(void);

#endif // TEST_LIB_H
