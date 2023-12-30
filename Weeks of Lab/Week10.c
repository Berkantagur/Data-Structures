#include <stdio.h>
#include <stdlib.h>
void peek();
int push(int item);
int pop();
void display();

typedef struct s{
    int item;
    struct  s *next; 
    };
    struct s *top = NULL;
    struct s *temp;

int push(int item){
    
    struct s *new_node ;
    top=(struct s*)malloc(sizeof(struct s));

    if (top == NULL) {
        printf("Memory error\n");
        return -1;
    }
    else {
        printf("%d\n",item);
        top->item = item;
        top->next = item;
        return 0;
    }
}

int pop(){
    int i;
    if(top==NULL){
        printf("Stack is empty\n");
        return -1;
    }
    else{
        printf("\nDeleted element = %d\n", top->item);
        temp = top;
        i = top->item;
        top = top -> next;
        free(temp);
        return i;
    }
}

void display(){
    
    temp = top;
    while (temp != NULL) {
        printf("Top element is %d ", temp -> item);
        temp = temp -> next;
    }
    
}

void peek(){

    if(top == NULL){
        printf("Stack is empty\n");
    }
    else{
        printf("%d \n", top->item);
    }
}


int main(){

    push(2);
    push(3);
    push(10);
    display();//top, ptr
    peek(); // topa döndür
    pop();// top değişmesin, free olmasın
    peek();
    display();
    return 0;
}