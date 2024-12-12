#include <stdio.h>
#include <string.h>

#define max 10

void main() 
{
	void bfs_traverse(int a[max][max], int n);
	void dfs_traverse(int a[max][max], int n, int start);

    int a[max][max];
    int start, n, i, j;

    start = 0;

    printf("\n Enter Size: ");
    scanf("%d", &n);

    printf("\n Enter Value ... \n");

    for (i = 0; i < n; i++) 
	{
        for (j = 0; j < n; j++) 
		{
            printf("\n Enter Value for (%d, %d): ", i, j);
            scanf("%d", &a[i][j]);
        }
        printf("\n");
    }

    bfs_traverse(a,n);
    dfs_traverse(a,n,start);
}

void bfs_traverse(int a[max][max], int n) 
{
    int i,j;
    int visited[max] = {0};
    int queue[max];
    int front = -1, rear = -1;

    queue[++rear] = 0;
    visited[0] = 1;

    printf("\n BFS Path:-> 0");

    while (front != rear) 
	{
        j = queue[++front];

        for (i = 0; i < n; i++) 
		{
            if (a[j][i] == 1 && visited[i] == 0) 
			{
                visited[i] = 1;
                queue[++rear] = i;
                printf(" :-> %d", i);
            }
        }
    }
}

void dfs_traverse(int a[max][max], int n, int start) 
{
    int stack[max];
    int visited[max] = {0};
    int top = -1;
    int i,current,found;

    stack[++top] = start;
    visited[start] = 1;

    printf("\n DFS Path:-> %d", start);

    while (top != -1) 
    {
        current = stack[top];

        found = 0;
        for (i = 0; i < n; i++) 
        {
            if (a[current][i] == 1 && visited[i] == 0) 
            {
                found = 1;
                visited[i] = 1;
                stack[++top] = i;
                printf(" :-> %d", i);
                break;
            }
        }

        if (found == 0) 
        {
            top--;
        }
    }
}
