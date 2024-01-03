#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

int push (int data){//Eleman ekleme

    if (top == NULL){//Stack is empty
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = data;
        new_node->next = NULL;
        top = new_node;
    } else {//Stack is not empty
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = data;
        new_node->next = top;
        top = new_node;
    }
    return 0;
}

int display(){

    if (top == NULL){
        printf("Stack is empty!");
    } else {
        struct node *index = top;
        while (index != NULL){
            printf("%d - ", index->data);
            index = index->next;
        }
        printf("\n");
    }
    return 0;
}

int pop(){

    if (top == NULL){
        printf("Stack is empty!");
    } else {
        struct node *temp = top;
        top = top->next;
        free(temp);
    }
    return 0;
}

int main(){
    
        int choice = 1;
        int input;
    
        while (choice){
            printf("Please enter the data: ");
            scanf("%d", &input);
            push(input);
            printf("Do you want to continue? (YES -> 1 // NO -> 0): ");
            scanf("%d", &choice);
        }

        printf("Original Stack is: ");
        display();

        while (choice = 0){
            printf("Please enter the data that you want to delete: ");
            scanf("%d", &input);
            pop(input);
            printf("Do you want to continue? (YES -> 0 // NO -> 1): ");
            scanf("%d", &choice);            
        }
        
        printf("After popping elements from stack is: ");
        display();

        return 0;
}

// STACK SUMMARY
// Stack is a linear data structure which follows a particular order in which the operations are performed.
// The order may be LIFO(Last In First Out) or FILO(First In Last Out).
// Mainly the following three basic operations are performed in the stack:
// Push: Adds an item in the stack. If the stack is full, then it is said to be an Overflow condition.
// Pop: Removes an item from the stack. The items are popped in the reversed order in which they are pushed.
// If the stack is empty, then it is said to be an Underflow condition.
// Peek or Top: Returns top element of stack.
// Display: Print the Stack.
// isEmpty: Returns true if stack is empty, else false.