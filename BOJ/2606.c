// 2606 바이러스
#include <stdio.h>

int cnt = 0;
int adj[101][101] = {0, };
int visited[101] = {0, };

void DFS(int n, int m, int cur) {
    for (int i = 1; i <= n; ++i) {
        if (visited[i] == 0 && adj[cur][i] == 1) {
            visited[i] = 1;
            cnt++;
            DFS(n, m, i);
        }
    }

    return;
}

int main(void)
{
    int n, m, a, b;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &a, &b);
        adj[a][b] = adj[b][a] = 1;    
    }
    visited[1] = 1;
    DFS(n, m, 1);
    printf("%d", cnt);
    return 0;
}