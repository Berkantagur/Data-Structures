#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Stack;

Stack *top = NULL;

int push(int item){

    Stack *newnode;
    newnode = (Stack *)malloc(sizeof(Stack));

    if(newnode == NULL){
        printf("ERROR, not enough memory");
        return -1;
    }else{
        newnode->data = item;
        newnode->next = top;
        top = newnode;
        return 0;
    }
}

int pop(){

    Stack *temp;
    int i;
    if(top == NULL){
        printf("ERROR, stack is empty");
        return -1;
    }
    else{
        temp = top;
        i = top->data;
        top = top->next;
        free(temp);
        return i;
    }
}

void display(){

    Stack *index;
    index = top;
    
    while(index != NULL){
        printf("%d ", index->data);
        index = index->next;
    }
    printf("\n");
}

int main(){

    int i;
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    display();
    i = pop();
    printf("Popped element is: %d\n", i);
    display();
    return 0;
}