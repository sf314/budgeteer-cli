
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <struct_utils.h>

transaction_t create_transaction(const char* desc, float amount) {
    transaction_t new_trans;

    memset(&new_trans, 0, sizeof(new_trans));

    strcpy(new_trans.description, desc);
    new_trans.amount = amount;

    return new_trans;
}

void add_transaction(transaction_node_t** head_ref, transaction_t new_transaction) {
        
    transaction_node_t* new_node = malloc(sizeof(transaction_node_t));
    new_node->transaction = new_transaction;
    new_node->next = NULL;
    
    // If empty, assign at head
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    
    // Find end of the list
    transaction_node_t* temp = *head_ref;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = new_node;
}

void remove_transaction_at_index(transaction_node_t* head, int index) {
    
}

void print_transactions(transaction_node_t** head_ref) {
    transaction_node_t* temp = *head_ref;
    
    if (temp == NULL) {
        return;
    }
    
    int index = 0;
    do {
        printf("%d: $%.2f - %s\n", index, temp->transaction.amount, temp->transaction.description);
        temp = temp->next;
        index++;
    } while (temp != NULL);
    
}