#include <stdio.h>

#define MAX_SIZE 100
                                        //total node         
void dfs(int graph[MAX_SIZE][MAX_SIZE], int vertices, int currentVertex, int visited[]) 
{
    printf("%d ", currentVertex);
    visited[currentVertex] = 1;

    for (int i = 0; i < vertices; i++)
     {
        if (graph[currentVertex][i] == 1 && !visited[i])
         {
            dfs(graph, vertices, i, visited);
        }
    }
}

int main() 
{
    int vertices;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    int graph[MAX_SIZE][MAX_SIZE];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < vertices; i++)
     {
        for (int j = 0; j < vertices; j++) 
        {
            scanf("%d", &graph[i][j]);
        }
    }

    int  visited[MAX_SIZE];

    printf("DFS traversal: ");
    for (int i = 0; i < vertices; i++) 
    {
        if (!visited[i]) 
        {
            dfs(graph, vertices, i, visited);
        }
    }

    return 0;
}