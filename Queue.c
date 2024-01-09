#include <stdio.h>
#include <stdlib.h>

struct node {

    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int item){

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->next = NULL;

    if(front == NULL && rear == NULL){

        front = rear = newnode;
    }
    else{

        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue(){

    struct node *temp = front;

    if(front == NULL){

        printf("\nQueue is empty!");
    }
    else if(front == rear){

        front = rear = NULL;
        free(temp);
    }
    else{

        front = front->next;
        free(temp);
    }
}

void display(){

    struct node *index = front;

    if(front == NULL){

        printf("\nQueue is empty!");
    }
    else{

        while(index != NULL){

            printf("%d ", index->data);
            index = index->next;
        }
    }
}

int main(){

    int choice;
    int item;

    while(1){

        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                printf("\nEnter the item to be inserted: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice!");
        }
    }
    return 0;
}