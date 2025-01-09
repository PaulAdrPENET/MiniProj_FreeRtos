#include "test.h"
#include <stdio.h>

int main() {
    //char * argv[];
    printf("=== Running Tests ===\n");
    test_t tests[] = {
            DECL_TEST(test_1),
            DECL_TEST(test_2),
            LAST_TEST
    };
    test_all(tests);

    return EXIT_SUCCESS;

}
