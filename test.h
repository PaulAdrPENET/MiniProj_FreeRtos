#ifndef TEST_LIB_H
#define TEST_LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TEST(function) int function(void)

void run_tests(void);

int test_1(void);
void test_2(void);
void test_3(void);

const char* strbool(int v);

#endif // TEST_LIB_H
