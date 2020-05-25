#ifndef _STRUCTURES_H
#define _STRUCTURES_H

#include <unistd.h>

#define DESCRIPTION_LEN 100
#define NAME_LEN 20
#define MAX_TRANSACTIONS 100

/**
 * A discrete transaction structure, meant to be referenced as a value.
 */
typedef struct __attribute__((packed)) {
    uint64_t timestamp;
    double amount;
    char description[DESCRIPTION_LEN];
} transaction_t;


/**
 * A node structure for a linked list of transactions, meant to be referenced 
 * as a pointer.
 */
typedef struct __attribute__((packed)) transaction_node_t {
    transaction_t transaction;
    struct transaction_node_t* next;
} transaction_node_t;


/**
 * A discrete budget structure, meant to be referenced as a value.
 */
typedef struct __attribute__((packed)) {
    double limit;
    transaction_t transactions[MAX_TRANSACTIONS];
    char name[NAME_LEN];
} budget_t;


/**
 * A node structure for a linked list of budgets, meant to be referenced as a 
 * pointer.
 */
typedef struct __attribute__((packed)) budget_node_t {
    budget_t budget;
    struct budget_node_t* next;
} budget_node_t;

#endif