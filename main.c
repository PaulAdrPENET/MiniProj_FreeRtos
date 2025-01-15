//
// Created by paula on 09/01/2025.
//
#include "main.h"

int main(){
    srand((unsigned int)time(NULL));

#ifdef ACTIVATE_TEST
    printf("=== Running Tests ===\n");
    test_t tests[] = {
            DECL_TEST(test_rand8),
            DECL_TEST(test_swap8),
            DECL_TEST(test_htobe),
            DECL_TEST(test_frames_generation),
            DECL_TEST(test_generate_random_order),
            DECL_TEST(test_sum_multiplex),
            //DECL_TEST(test)
#ifdef ADVANCED_TEST_INFO
            DECL_TEST(test_print_frames),
            DECL_TEST(test_print_multiplex),
            DECL_TEST(test_print_parse_signal),
#endif
            LAST_TEST
    };
    test_all(tests);
#endif

    return EXIT_SUCCESS;
}