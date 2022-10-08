// 1707 달팽이사각형
#include <cstdio>

int board[110][110] = {0, };
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

int in_range(int n, int y, int x) {
    return 1 <= y && 1 <= x && y <= n && x <= n; 
}

int main(void) {
    int n, number = 1, cy = 1, cx = 1;

    scanf("%d", &n);

    while (in_range(n, cy, cx) && !board[cy][cx]) {
        for (int dir = 0; dir < 4; ++dir) {
            if (!in_range(n, cy, cx) || board[cy][cx])
                break;
            
            while (1) {
                board[cy][cx] = number++;

                int ny = cy + dy[dir];
                int nx = cx + dx[dir];

                if (!in_range(n, ny, nx) || board[ny][nx] != 0) {
                    cy += dy[(1 + dir) % 4];
                    cx += dx[(1 + dir) % 4];
                    break;
                }

                cy = ny, cx = nx; 
            }
        }
    }    

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    return 0;
}