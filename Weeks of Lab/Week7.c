// HASHING
// Exam Topic
#include <stdio.h>
#include <stdlib.h>
#define TABLE_SİZE 10;
void insert();
void display();
void search();
int loopinput();

int hash(int key);
int array [TABLE_SİZE] = {NULL};
int i, key, hkey;

int main() {

int choice;

printf("1->> Insert\n2->>Display\n3->>Search\n4->>Exit\n");
printf("Please enter a oparator: ");
scanf("%d",&choice);

switch (choice){

    case 1:
        loopinput();
        break;
    case 2:
        
        break;
    case 3:
        
        break;
    case 4:
        
        break;
}

    return 0;
}

int loopinput(){
        
        printf("\nEnter the number of elements you want to input in hashing table : ");
        scanf("%d",&i);

        for(int j=0;j<i;j++){
            printf("Enter a number: ");
            scanf("%d",&key);
            hash(key);

        }
        
        insert();
    
}

void insert(){
    
    int index;

    if (j = 0; k<TABLE_SİZE; j++) {
    index = hash(hkey)%TABLE_SİZE;

    if(hash[index] == NULL){

        hash[index] = key;
    }
    else{
        for(int i=0;i<TABLE_SİZE;i++){
            index = (index+1)%TABLE_SİZE;
            if(hash[index] == NULL){
                hash[index] = key;
                break;
            }
        }
    }
    }

}

int hash(int key){
    
    hkey = (2*key+3) % 10;
    return hkey;
}