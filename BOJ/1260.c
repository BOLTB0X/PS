// 1260 DFS와 BFS
#define Max 1001
#include <stdio.h>
#include <string.h>

int fr = 0, re = 0;
int que[Max * Max / 2];

void enqueue(int data) {
    que[re++] = data;
}

int adj[Max][Max] = {0, };
int visited[Max] = {0, };

void DFS(int n, int m, int cur) 
{
    visited[cur] = 1;
    printf("%d ", cur);

    for (int i = 1; i <= n; ++i) 
    {
        if (adj[cur][i] == 1 && visited[i] == 0)
        {
            DFS(n, m, i);
        }
    }
    return;
}

void BFS(int n, int m, int start)
{
    enqueue(start);
    visited[start] = 1;

    while (fr < re)
    {
        int cur = que[fr++];
        printf("%d ", cur);

        for (int i = 1; i <= n; ++i) 
        {
            if (visited[i] == 0 && adj[cur][i] == 1)
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    return;
}

int main(void)
{
    int n, m, v, val1, val2;

    scanf("%d %d %d", &n, &m, &v);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &val1, &val2);

        adj[val1][val2] = 1;
        adj[val2][val1] = 1;
    }

    DFS(n, m, v);
    memset(visited, 0, sizeof(visited));
    printf("\n");
    BFS(n, m, v);
    return 0;
}