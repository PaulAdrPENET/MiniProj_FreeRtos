#include "test.h"

void run_tests(void){
    printf("=== Running Tests ===\n");
    printf(strbool(test_1()));
};

int test_1(void){
    return 1;
};

void test_2(void){

};

void test_3(void){
};

const char* strbool(int v){
    static const char* array[2] = {
            "[FAILED]",
                "[PASSED]"};
    return array [v & 1];
}