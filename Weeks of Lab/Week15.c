#include <stdio.h>
#include <conio.h>
#define MAX 5

// BFS Function
void BFS(int adj[][MAX], int visited[], int start)
{
    int queue[MAX], rear = -1, front = -1, i, k;
    for (k = 0; k < MAX; k++)
        visited[k] = 0;
    queue[++rear] = start;
    ++front;
    visited[start] = 1;

    while (rear >= front)
    { // queue is not empty
        start = queue[front++];
        printf("%c-", start + 65);

        for (i = 0; i < MAX; i++)
        { // add neighbours
            if (adj[start][i] && visited[i] == 0)
            {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

// DFS Function

void DFS(int adj[][MAX], int visited[], int start)
{
    int stack[MAX], top = -1, i, k;
    for (k = 0; k < MAX; k++)
        visited[k] = 0;

    stack[++top] = start;
    visited[start] = 1;

    while (top != -1)
    { // stack is not empty
        start = stack[top--];
        printf("%c-", start + 65);

        for (i = 0; i < MAX; i++)
        { // add neighbors
            if (adj[start][i] && visited[i] == 0)
            {
                stack[++top] = i;
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int visited[MAX] = {0};
    int adj[MAX][MAX], i, j;
    int option, size;

    do
    {
        printf("\n 1.Enter values in graph");
        printf("\n 2.BFS Traversal");
        printf("\n 3.DFS Traversal");
        printf("\n 4.Exit");
        printf("\n\n Enter your option : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("\n Enter the adjacency matrix: \n");
            for (i = 0; i < MAX; i++)
            {
                printf("Enter row %d (separate each element with a space): ", i + 1);
                for (j = 0; j < MAX; j++)
                    scanf("%d", &adj[i][j]);
            }
            break;
        case 2:
            printf("BFS traversal: ");
            BFS(adj, visited, 0);
            break;
        case 3:
            printf("DFS traversal: ");
            DFS(adj, visited, 0);
            break;
        }
    } while (option != 4);
    getch();
    return 0;
}
