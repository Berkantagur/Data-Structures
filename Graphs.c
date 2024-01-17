#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 5
#define MAX_EDGES 5

struct Array {
    int value;
    int adjencyMatrix[MAX_VERTICES][MAX_EDGES];
    int visited[MAX_VERTICES];
};

struct Array *createArray(){
    printf("Please enter the adjecency matrix:");
    struct Array *array = (struct Array *)malloc(sizeof(struct Array));
    for(int i = 0; i < MAX_VERTICES; i++){
        for(int j = 0; j < MAX_EDGES; j++){
            printf("Enter row %d (separate each element with a space): ");
            scanf("%d ", &array->adjencyMatrix[i][j]);
        }
    }
    return array;
} 

int main(){

    while(1){
                
        int choice;
        printf("1. Enter values in graph\n");
        printf("2. BFS Traversal\n");
        printf("3. DFS Traversal\n");
        printf("4. Exit\n\n");
        printf("Enter your option : ");

        scanf("%d", &choice);
        switch(choice){
            case 1:
                struct Array *array = createArray();
                break;
            case 2:
                printf("BFS Traversal: ");
                bfsTraversal(array, 1);
                break;
            case 3:
                printf("DFS Traversal: ");
                dfsTraversal(array, 1);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid option\n");
        }
    }
    return 0;
}