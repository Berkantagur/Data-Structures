#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
    char title[50];
    char author[50];
    int pages;
    float price;
};

int main (){
    /*
    //Directed
    struct book book1;
    strcpy(book1.title, "Atomic Habits");
    strcpy(book1.author, "James Clear");
    book1.pages = 319;
    book1.price = 15.99;
    
    printf("Information about the book:\nTitle: %s\nAuthor: %s\nPages: %d\nPrice: %f\n", book1.title, book1.author, book1.pages, book1.price);
    */
    //Undirected
    struct book *book2;
    book2 = (struct book*)malloc(sizeof(struct book));
    strcpy(book2->title, "The Power of Habit");
    strcpy(book2->author, "Charles Duhigg");
    book2->pages = 371;
    book2->price = 12.99;

    printf("Information about the book:\nTitle: %s\nAuthor: %s\nPages: %d\nPrice: %f\n", book2->title, book2->author, book2->pages, book2->price);
    free(book2);
    return 0;
}