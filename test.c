#include "test.h"

/*
const char* strbool(int v){
    static const char* array[2] = {
            "[FAILED]",
            "[PASSED]"};
    return array [v & 1];
}
 */

void test_all(test_t * test){
    for (;test->call;test++){
        int ret = test->call(); //0 ou 1
        const char* status = ret ? "[PASSED]" : "[FAILED]";
        printf("%s %s \n",test->name, status);
    }
}

int test_1(void){
    return 1;
};

int test_2(void){
    return 0;
};