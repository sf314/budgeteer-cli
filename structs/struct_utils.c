
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

void remove_transaction_at_index(transaction_node_t** head_ref, int target) {

    // If empty, assign at head
    if (*head_ref == NULL) {
        printf("Cannot remove transaction %d. The list is empty.\n", target);
        return;
    }

    // If target is head:
    if (target == 0) {
        transaction_node_t* temp = *head_ref;
        *head_ref = (*head_ref)->next;
        free(temp);
        return;
    }

    // Move to node just before the target
    transaction_node_t* temp = *head_ref;
    for (int index = 0; index < target - 1; index++) {
        temp = temp->next;

        if (temp == NULL) {
            printf("Cannot remove transaction %d. The list is not large enough.\n", target);
            return;;
        }
    }

    if (temp->next == NULL) {
        printf("Nothing to remove\n");
        return;
    }

    // Remove the target
    transaction_node_t* target_node = temp->next;
    temp->next = temp->next->next;

    free(target_node);
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

int length(transaction_node_t** head_ref) {

    transaction_node_t* temp = *head_ref;
    int length = 0;
    while (temp != NULL) {
        temp = temp->next;
        length++;
    }

    return length;
}