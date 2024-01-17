#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;    
};

struct node *head = NULL;
struct node *new_node;
struct node *temp;

int addNode(int data){

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = temp = new_node;
    } else {
        temp->next = new_node;
        temp = new_node;
    }
    return 0;
}

int addNodeHead(int data){

    if (head == NULL) {//Linked List is Empty
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = data;
        new_node->next = NULL;

        head = temp = new_node;
    } else {//Linked List is not Empty
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node ->data = data;
        new_node->next = head;
        head = new_node;
    }
    return 0;
}

void deleteNode(int data){

    temp = head;
    struct node *prev;

    if (temp != NULL && temp->data == data) {
        head = temp->next;
        free(temp);
    }

    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        printf("Data is not present in the list!");

    prev->next = temp->next;
    free(temp);
}

int print(){
    
    temp = head;
    printf("Original Linked List: ");

    while (temp != NULL) {
        printf("%d  -  ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    return 0;  
}

int main () {

    int input, inputOp;
    int choice = 1;

    while (choice) {


        printf("Please enter the data: ");
        scanf("%d", &input);

        printf("Please choice an operator: Add Data Head -> 1  Add Data Normally -> 2: ");
        scanf("%d", &inputOp);

        if (inputOp == 1) addNodeHead(input);
        else if (inputOp == 2) addNode(input);
        else printf("Please choice a valid operator!!!");

        printf("\nDo you want to continue?\n Press 0 for No and 1 for Yes: ");
        scanf("%d", &choice);
    }
    print();
    printf("Do you want to delete the any data?\n Press 0 for No and 1 for Yes: ");
    scanf("%d", &choice);

    while (choice){
        printf("Please enter the data you want to delete: ");
        scanf("%d", &input);
        deleteNode(input);
        printf("Do you want to delete the any data?\n Press 0 for No and 1 for Yes: ");
        scanf("%d", &choice);
    }
    print();
    return 0;
}