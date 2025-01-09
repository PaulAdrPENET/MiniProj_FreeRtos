//
// Created by paula on 09/01/2025.
//
#include "main.h"

int main(){
    srand((unsigned int)time(NULL));

    printf("=== Running Tests ===\n");
    test_t tests[] = {
            DECL_TEST(test_1),
            DECL_TEST(test_2),
            DECL_TEST(test_frames),
            LAST_TEST
    };
    test_all(tests);
    return EXIT_SUCCESS;
}