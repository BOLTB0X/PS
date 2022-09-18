// 10026 적록색약
#include <stdio.h>
#include <string.h>

char board[101][101];
int visited[101][101];

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

void DFS(int n, int y, int x) {
    for (int dir = 0; dir < 4; ++dir) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if (ny < 0 || nx < 0 || ny >= n || nx >= n)
            continue;
        
        if (visited[ny][nx] == 1 || board[ny][nx] != board[y][x])
            continue;

        visited[ny][nx] = 1;
        DFS(n, ny, nx);
    }
    return;
}

int main(void) 
{
    int n, ans1 = 0, ans2 = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", board[i]);
    }

    // 초기화
    memset(visited, 0, sizeof(visited)); 

    // 색맹 X
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (visited[i][j] == 0) {
                visited[i][j] = 1;
                DFS(n, i, j);
                ans1++;
            }
        }
    }

    memset(visited, 0, sizeof(visited));

    // 색맹 O
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == 'G')
                board[i][j] = 'R';
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (visited[i][j] == 0) {
                visited[i][j] = 1;
                DFS(n, i, j);
                ans2++;
            }
        }
    }

    printf("%d %d", ans1, ans2);
    return 0;
}