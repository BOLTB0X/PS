// 11724 연결 요소의 개수
#include <stdio.h>
#define Max_len 1001

int adj[Max_len][Max_len] = {0, };
int visited[Max_len] = {0, };

void DFS(int n, int m, int cur) {
    visited[cur] = 1;

    for (int i = 1; i <= n; ++i) {
        if (adj[cur][i] == 1 && visited[i] == 0) {
            DFS(n, m, i);
        }
    }

    return;
}

int main(void)
{
    int n, m, a, b, ans = 0;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &a, &b);

        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    for (int i = 1; i <= n; ++i) {
        if (visited[i] == 0) {
            DFS(n, m, i);
            ans++;
        }
    }

    printf("%d", ans);
    return 0;
}