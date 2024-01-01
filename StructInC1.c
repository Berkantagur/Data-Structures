#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[30];
    int age;
} authorr;

int main (){
    /*
    //Direct
    authorr author1;
    strcpy(author1.name, "James Clear");
    author1.age = 34;
    printf("Information about the Author:\nName: %s\nAge: %d\n", author1.name, author1.age);
    */

    //Undirect
    authorr *author2;
    author2 = (authorr*)malloc(sizeof(authorr));
    strcpy(author2->name, "Charles Duhigg");
    author2->age = 47;
    printf("Information about the Author:\nName: %s\nAge: %d\n", author2->name, author2->age);
    free(author2);

    return 0;
}