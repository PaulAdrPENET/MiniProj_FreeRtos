#ifndef TEST_LIB_H
#define TEST_LIB_H

#include <stdio.h>
#include <stdbool.h>

// Définition des types de tests
typedef struct {
    const char *test_name;
    bool (*test_function)(void); // Pointeur vers la fonction de test
} TestCase;

// Prototype pour initialiser la librairie de test
void init_test_library(void);

// Prototype pour exécuter les tests
void run_tests(const TestCase *tests, int num_tests);

// Fonction utilitaire pour afficher les résultats
void print_test_result(const char *test_name, bool success);

#endif // TEST_LIB_H
