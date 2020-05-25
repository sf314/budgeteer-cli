#ifndef _STRUCTURES_H
#define _STRUCTURES_H

#include <unistd.h>

#define DESCRIPTION_LEN 100
#define NAME_LEN 20
#define MAX_TRANSACTIONS 100

typedef struct __attribute__((packed)) {
    uint64_t timestamp;
    double amount;
    char description[DESCRIPTION_LEN];
} transaction_t;

typedef struct __attribute__((packed)) {
    double limit;
    transaction_t transactions[MAX_TRANSACTIONS];
    char name[NAME_LEN];
} budget_t;

#endif