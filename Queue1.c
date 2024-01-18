#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Que;

Que *front = NULL;
Que *rear = NULL;

int enque(int item){

    Que *newnode;
    newnode = (Que *)malloc(sizeof(Que));

    if(newnode == NULL){
        printf("Queue is fully.\n");
        return -1;
    }

    newnode->data = item;
    newnode->next = NULL;

    if(front == NULL){
        front = newnode;
        rear = newnode;
    }
    else{
        rear->next = newnode;
        rear = newnode;
    }
    return 0;
}

int dequeue(){

    Que *temp;
    int item;

    if(front == NULL){
        printf("Queue is empty.\n");
        return -1;
    }

    temp = front;
    front = front->next;

    if(front = NULL){
        rear = NULL;
    }

    item = temp->data;
    free(temp);
    return item;
}

void reset(){

    Que *temp;
    temp = front;

    while(temp){
        front = front->next;
        free(temp);
        temp = front;
    }
    rear = NULL;
}

void display(){

    Que *index;
    index = front;

    printf("Queue is: ");
    while(index != NULL){
        printf("%d ", index->data);
        index = index->next;
    }
    printf("\n");
}

int main(){

    int choice, item;

    while(1){
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Reset\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the item: ");
                scanf("%d", &item);
                enque(item);
                break;
            case 2:
                item = dequeue();
                if(item != -1){
                    printf("Dequeued item is: %d\n", item);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                reset();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}