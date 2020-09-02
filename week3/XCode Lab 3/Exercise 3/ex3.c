//
//  ex3.c
//  Exercise 3
//
//  Created by Roman Nabiullin on 01.09.2020.
//  Copyright © 2020 Innopolis Univesity. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

// node of a list
struct node {
    int value;
    struct node* next;
};

void insert_node(struct node **head, int val);
void delete_node(struct node **head, int val);
void print_list(struct node *head);

void insert_node(struct node **head, int val) {
    
    // memory allocation
    struct node *new_node = malloc(sizeof(struct node));
    
    // creating new node
    new_node->value = val;
    new_node->next = *head;
    
    // shifting
    *head = new_node;
}

void delete_node(struct node **head, int val) {
    
    struct node *prev;
    prev = *head;

    // case: there are no nodes at all
    if (*head == NULL) {
        return;
    }
    
    // case: removing head node
    if ((*head)->value == val) {
        *head = (*head)->next;
        
        // deallocate memory
        free(prev);
        return;
    }

    // searching for the node to remove
    while (prev->next != NULL && (prev->next)->value != val) {
        prev = prev->next;
    }
    
    // removing a node
    if (prev->next != NULL) {
        struct node *to_remove = prev->next;
        prev->next = to_remove->next;
        
        // deallocate memory
        free(to_remove);
        return;
    }
}

void print_list(struct node *head) {
    while (head != NULL) {
        printf("%d ", head->value);
        head = head->next;
    }
}

int main(int argc, const char * argv[]) {
    struct node *head = NULL;
    
    insert_node(&head, 0);
    insert_node(&head, 16);
    insert_node(&head, 42);
    insert_node(&head, -8);
    insert_node(&head, 98);
    
    print_list(head);
    printf("\n\n");
    
    delete_node(&head, -8);
    print_list(head);
    
    return 0;
}
