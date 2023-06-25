#include<stdio.h>
void BFS( int graph[10][10],int total,int visited[10] ,int vertes)
{
    int j;
    printf("%d\t",vertes);
    visited[vertes]=1;  //visited ho gaya
    for( j=0;j<=total;j++)
    {
        if(!visited[j] && graph[vertes][j]==1)
        {
            BFS(j);
        }
    }
}
int main()
{
    int graph[10][10],visited[10],total;  
    int i,j;
    printf("enter a total number of vertices\n");
    scanf("%d",&total);
    printf("\n enter a adjacency matrix\n");
    for(int i=0;i<total;i++)
    {
        for(j=0;j<total;j++)
        {
             scanf("%d",&graph[i][j]);
        }
    }
    for(i=0;i<total;i++)
   {
        visited[i]=0;
    }
 BFS(graph,total, visited,0 );
}