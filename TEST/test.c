//
// Created by paula on 09/01/2025.
//

#include "test.h"

void test_all(test_t * test){
    for (;test->call;test++){
        int ret = test->call(); //0 ou 1
        const char* status = ret ? "[PASSED]" : "[FAILED]";
        printf("%s %s \n",test->name, status);
    }
}
