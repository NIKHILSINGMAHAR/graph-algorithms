//Kruskal algo to find min spanning tree
#include <stdio.h>
int parent[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
int find(int n)
{

   if (parent[n] == -1)
   {
      return n;
   }
   parent[n] = find(parent[n]);
   return parent[n];
}
void unionn(int a, int b)
{
   parent[find(a)] = find(b);
}

int main()
{
   // Write C code here
   int n;
   printf("Enter the number of edges: ");
   scanf("%d", &n);
   int a[n][3];
   for (int i = 0; i < n; i++)
   {
      scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
   }

   // sorting
   for(int i=0;i<n-1;i++)
   {
        for(int j=i+1;j<n;j++)
        {
            if(a[i][0]>a[j][0])
            {
                int temp=a[i][0];
                a[i][0]=a[j][0];
                a[j][0]=temp;

                int temp=a[i][1];
                a[i][1]=a[j][1];
                a[j][1]=temp;

                int temp=a[i][2];
                a[i][2]=a[j][2];
                a[j][2]=temp;
            }
        }
   }   
//    for (int i = 0; i < n; i++)
//    {
//       int minind = i;
//       for (int j = i + 1; j < n; j++)
//       {
//          if (a[minind][0] > a[j][0])
//             minind = j;
//       }
//       if (minind != i)
//       {
//          // swap
//          int t;
//          t = a[minind][0];
//          a[minind][0] = a[i][0];
//          a[i][0] = t;
//          t = a[minind][1];
//          a[minind][1] = a[i][1];
//          a[i][1] = t;
//          t = a[minind][2];
//          a[minind][2] = a[i][2];
//          a[i][2] = t;
//       }
//    }
   // sorted
   for (int i = 0; i < n; i++)
   {
      printf("sorted array: ");
      printf("%d %d %d\n", a[i][0], a[i][1], a[i][2]);
   }

   for (int i = 0; i < n; i++)
   {
      if (find(a[i][1]) != find(a[i][2]))
      {
         unionn(a[i][1], a[i][2]);
         printf("nodes that will make min span tree: ");
         printf("--%d--%d--\n", a[i][1], a[i][2]);
      }
   }

   return 0;
}