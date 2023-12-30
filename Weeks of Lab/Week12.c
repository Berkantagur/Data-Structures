// enqueue -> insertion  front=0, rear=0, new_node = malloc
// struct yapısında datayı tanımladıktan sonra temp ve next fonksiyonlarını tanımla
// kuyrukta hiç eleman yoksa front ve rear = 0 ise if else ile
// kuyrukta eleman varsa rear ı arttır ve next i rear a eşitle
// dequeue front = front-> next
// display döngülü şekilde temp datasını yazdır, sonra tempi güncelle (next)
// peak döngüsüz front yazdır.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
    struct node *front = 0;
    struct node *rear = 0;
    struct node *temp;

void enqueue(int item){

    struct node *new_node;
    new_node = (struct node*)malloc(sizeof(struct node));

    if (new_node == NULL) {
        printf("Memory error!!!\n");
    }
    else {
        new_node->data = item;
        new_node->next = NULL;
        
        if (front == 0 && rear == 0) {
            front = rear = new_node;
        }
        else {
            rear->next = new_node;
            rear = new_node;
        }
    }
}

void dequeue(){

    if (front == 0 && rear == 0) {
        printf("Queue is empty!!!\n");
    }
    else {
        printf("Removed element is %d\n", front->data);
        temp = front;
        front = front->next;
        free(temp);
    }
}

void display(){

    temp = front;
    if (front == 0 && rear == 0) {
        printf("Queue is empty!\n");
    }
    else {
        while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
        printf("\n");
        }
    }
}

void peek(){

    if (front == 0 && rear == 0) {
        printf("Queue is empty!!!\n");
    }
    else {
        printf("Front element is %d\n", front->data);
    }
}

int main() {

    display();
    enqueue(8);
    enqueue(2);
    enqueue(-1);
    display();
    dequeue();
    display();
    peek();
    enqueue(4);
    display();

    return 0;
}