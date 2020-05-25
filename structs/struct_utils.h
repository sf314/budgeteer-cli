#ifndef _STRUCT_UTILS_H
#define _STRUCT_UTILS_H

/**
 * Budgeteer Struct Utils file
 * Easily create, remove, and reorder structs in a list. Requires simple linked
 * list implementation.
 * Stephen Flores
 */

#include <structures.h>

// ***** Node definitions for linked lists
typedef struct __attribute__((packed)) transaction_node_t {
    transaction_t transaction;
    struct transaction_node_t* next;
} transaction_node_t;

typedef struct __attribute__((packed)) budget_node_t {
    budget_t budget;
    struct budget_node_t* next;
} budget_node_t;


// ***** Function declarations for transaction nodes

/**
 * Create4 a transaction given some input data. This abstracts the production process
 * @param desc A string describing the transaction
 * @param amount The cost of the transaction
 * @return A new transaction_t structure
 */
transaction_t create_transaction(const char* desc, float amount);

/**
 * Add transaction to list
 * @param head The head of list to modify.
 * @param new_transaction The new item to add to the list.
 */
void add_transaction(transaction_node_t** head, transaction_t new_transaction);

/**
 * Remove transaction from a list at a given index
 * @param head The head of list to modify.
 * @param index The index of the item to remove. If it exceeds the list size, then nothing occurs.
 */
void remove_transaction_at_index(transaction_node_t** head, int target);

/**
 * Print all transactions for a list
 * @param head The head of list to print.
 */
void print_transactions(transaction_node_t** head);



#endif