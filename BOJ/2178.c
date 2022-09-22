// 2178 미로 탐색
#define MAX 101
#include <stdio.h>

typedef struct
{
    int y, x;
} Pos;

Pos que[MAX * MAX];

int fr = 0, re = 0;
int board[MAX][MAX];
int visited[MAX][MAX] = {0, };

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

void BFS(int n, int m, int y, int x) {
    Pos start;
    start.y = y, start.x = x;
    visited[y][x] = 1;
    que[re++] = start;

    while (fr < re) {
        Pos cur = que[fr++];
        for (int dir = 0; dir < 4; ++dir) {
            int ny = cur.y + dy[dir];
            int nx = cur.x + dx[dir];

            if ((0 <= ny && 0 <= nx && ny < n && nx < m) && 
                visited[ny][nx] == 0 && board[ny][nx] == 1) {
                visited[ny][nx] = visited[cur.y][cur.x] + 1;
                Pos next;
                next.y = ny, next.x = nx;
                que[re++] = next;
            }
        }
    }

    return;
}

int main(void)
{
    int n, m, ans = 0;

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%1d", &board[i][j]);
        }
    }

    BFS(n, m, 0, 0);
    ans = visited[n - 1][m - 1];
    printf("%d", ans);
    return 0;
}