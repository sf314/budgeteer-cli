/**
 * Budgeteer CLI Main file
 * Stephen Flores
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <structures.h>

#define INPUT_LEN 100


int main() {
    printf("Starting Budgeteer CLI...\n");

    // Declare global input param
    char* input = malloc(INPUT_LEN);
    memset(input, 0, INPUT_LEN);

    int should_continue = 1;
    while (should_continue) {
        // Print menu
        printf("### Main menu: ###\n");
        printf("1. Say hello\n");
        printf("2. Say goodbye\n");
        printf("0. Quit\n");

        // Fetch numerical input
        printf("> ");
        scanf("%s", input);
        int selection = atoi(input);
        printf("Selected: %d\n", selection);

        // Switch on results
        switch (selection) {
        case 1:
            printf("Hello!\n");
            break;
        case 2:
            printf("Goodbye!\n");
            break;
        case 0:
            printf("Exiting app\n");
            should_continue = 0;
            break;
        default:
            printf("Undefined input value %d!\n", selection);
            break;
        }
    }


    return 0;
}