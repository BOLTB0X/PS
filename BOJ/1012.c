// 1012 유기농 배추
#include <stdio.h>
#include <string.h>

int board[51][51] = {0, };
int visited[51][51] = {0, };

// 상하좌우
const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

void DFS(int n, int m, int y, int x) {
    for (int dir = 0; dir < 4; ++dir) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if (ny < 0 || nx < 0 || nx >= m || ny >= n)
            continue;

        if (visited[ny][nx] == 1)
            continue;

        if (board[ny][nx] == 0)
            continue;

        visited[ny][nx] = 1;
        DFS(n, m, ny, nx);
    }

    return;
}

int solution(int n, int m, int k) {
    int answer = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == 1 && visited[i][j] == 0) {
                answer++;
                visited[i][j] = 1;
                DFS(n, m, i, j);
            }
        }
    }

    return answer;
}

int main(void) {
    int T;
    int n, m, k, y, x;
    scanf("%d", &T);

    while (T--) {
        scanf("%d %d %d", &m, &n, &k);
        for (int i = 0; i < k; ++i) {
            scanf("%d %d", &x, &y);
            board[y][x] = 1;
        }

        int ret = solution(n, m, k);
        printf("%d\n", ret);

        memset(board, 0, sizeof(board));
        memset(visited, 0, sizeof(visited));
    }

    return 0;
}