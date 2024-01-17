#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 5
#define MAX_EDGES 5

struct Array
{
    int value;
    int adjencyMatrix[MAX_VERTICES][MAX_EDGES];
    int visited[MAX_VERTICES];
};

struct Array *createArray()
{
    printf("Please enter the adjecency matrix: ");
    struct Array *array = (struct Array *)malloc(sizeof(struct Array));
    for (int i = 0; i < MAX_VERTICES; i++)
    {
        for (int j = 0; j < MAX_EDGES; j++)
        {
            printf("Enter row %d (separate each element with a space): ", i + 1);
            scanf("%d ", &array->adjencyMatrix[i][j]);
        }
    }
    return array;
}

void bfsTraversal(struct Array *array, int start)
{
    for (int i = 0; i < MAX_VERTICES; i++)
    {
        array->visited[i] = 0;
    }
    int queue[MAX_VERTICES], front = 0, rear = 0;
    array->visited[start] = 0;
    queue[rear++] = start;
    while (front != rear)
    {
        start = queue[front++];
        printf("%c ", start + 65);
        for (int i = 0; i < MAX_VERTICES; i++)
        {
            if (array->adjencyMatrix[start][i] && !array->visited[i])
            {
                queue[rear++] = i;
                array->visited[i] = 1;
            }
        }
    }
    printf("\n\n");
}

void dfsTraversal(struct Array *array, int start)
{
    array->visited[start] = 1;
    printf("%d ", start);
    for (int i = 0; i < MAX_VERTICES; i++)
    {
        if (array->adjencyMatrix[start][i] && !array->visited[i])
        {
            dfsTraversal(array, i);
        }
    }
    printf("\n\n");
}

int main()
{

    while (1)
    {

        int choice;
        printf("1. Enter values in graph\n");
        printf("2. BFS Traversal\n");
        printf("3. DFS Traversal\n");
        printf("4. Exit\n\n");
        printf("Enter your option : ");

        scanf("%d", &choice);
        switch (choice)
        {
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