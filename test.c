/**
 * Budgeteer CLI Test file
 * Stephen Flores
 */

#include <stdio.h>
#include <stdlib.h>

#include <time.h>
#include <string.h>
#include <math.h>

#include <structures.h>
#include <struct_utils.h>

#define TEST_PASS 1
#define TEST_FAIL 0

// Predefines:
int test_datastructures(void);
int test_time(void);
int test_add_transaction(void);
int test_print_transaction(void);

int main() {
    int total_tests = 4;
    int num_passed = 0;
    num_passed += test_time();
    num_passed += test_datastructures();
    num_passed += test_add_transaction();
    num_passed += test_print_transaction();

    printf("Tests passed: %d of %d\n", num_passed, total_tests);

    if (num_passed != total_tests) {
        printf("WARNING: %d tests failed.\n", total_tests - num_passed);
        return 1;
    }

    return 0;
}

int test_datastructures() {
    // Create a new transaction manually
    transaction_t trans1;
    memset(&trans1, 0, sizeof(trans1));
    strcpy(trans1.description, "Hello, there!");
    trans1.amount = 12.34;
    printf("%s: $%2f\n", trans1.description, trans1.amount);

    // Create a new budget manually
    budget_t budget1;
    memset(&budget1, 0, sizeof(budget1));
    strcpy(budget1.name, "Budget 1");
    budget1.limit = 200.0;
    budget1.transactions[0] = trans1;
    budget1.transactions[1] = trans1;
    printf("%s: $%.2f\n", budget1.name, budget1.limit);

    for (int index = 0; index < MAX_TRANSACTIONS; index++) {
        transaction_t t = budget1.transactions[index];
        if (t.amount == 0.00) {break;}
        printf("  T%d - %s: $%.2f\n", index, t.description, t.amount);
    }

    return TEST_PASS;
}

int test_time() {
    printf("Current time: %lu\n", (unsigned long)time(NULL));
    return TEST_PASS;
}

int test_add_transaction() {
    // Create the starting node
    transaction_node_t* head = NULL;

    // Run test
    transaction_t new_trans = create_transaction("Hello, there", 1.23);

    // Verify the test
    if (fabs(new_trans.amount - 1.23) > 0.0000001) {
        printf("New transaction is not 1.23, but rather %f\n", new_trans.amount);
        return TEST_FAIL;
    }

    add_transaction(&head, new_trans);
    add_transaction(&head, new_trans);

    // Check print function
    print_transactions(&head);

    return TEST_PASS;
}

int test_print_transaction() {
    // Create sample transactions
    transaction_node_t* head = NULL;
    transaction_t t1 = create_transaction("First!", 1.23);
    transaction_t t2 = create_transaction("Second!", 2.49);

    add_transaction(&head, t1);
    add_transaction(&head, t2);

    // Run test
    print_transactions(&head);

    return TEST_PASS;
}