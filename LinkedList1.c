#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void deleteNode(struct node **head_ref, int key) {
    struct node *temp = *head_ref, *prev;

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    // Search for the key to be deleted, keep track of the previous node
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in the linked list
    if (temp == NULL)
        printf("Key is not present in the list!");

    // Unlink the node from the linked list
    prev->next = temp->next;

    free(temp);
}

int main() {
    struct node *head, *newnode, *temp;
    head = NULL;
    int choice = 1; 

    while (choice) {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
        printf("Do you want to continue (0,1)? ");
        scanf("%d", &choice);
    }
    temp = head;
    printf("Original Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    int key;
    printf("Enter the element to delete: ");
    scanf("%d", &key);
    deleteNode(&head, key);

    printf("Linked List after deletion of %d: ", key);
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    return 0;
}