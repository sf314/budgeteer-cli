/**
 * Budgeteer CLI Test file
 * Stephen Flores
 */

#include <stdio.h>
#include <stdlib.h>

#include <time.h>
#include <string.h>

#include <structures.h> 

#define TEST_PASS 1
#define TEST_FAIL 0

// Predefines:
int test_datastructures(void);
int test_time(void);

int main() {
    int total_tests = 2;
    int num_passed = 0;
    num_passed += test_time();
    num_passed += test_datastructures();
    
    printf("Tests passed: %d of %d\n", num_passed, total_tests);
    
    if (num_passed != total_tests) {
        printf("WARNING: %d tests failed.\n", total_tests - num_passed);
        return 1;
    }
    
    return 0;
}

int test_datastructures() {
    transaction_t trans1;
    memset(&trans1, 0, sizeof(trans1));
    strcpy(trans1.description, "Hello, there!");
    trans1.amount = 12.34;
    printf("%s: %2f\n", trans1.description, trans1.amount);

    budget_t budget1;
    memset(&budget1, 0, sizeof(budget1));
    strcpy(budget1.name, "Budget 1");
    budget1.limit = 200.0;
    budget1.transactions[0] = trans1;
    budget1.transactions[1] = trans1;
    printf("%s: %2f\n", budget1.name, budget1.limit);

    for (int index = 0; index < MAX_TRANSACTIONS; index++) {
        transaction_t t = budget1.transactions[index];
        if (t.amount == 0.00) {break;}
        printf("  T%d - %s: %.2f\n", index, t.description, t.amount);
    }

    return TEST_PASS;
}

int test_time() {
    printf("Current time: %lu\n", (unsigned long)time(NULL));
    return TEST_PASS;
}