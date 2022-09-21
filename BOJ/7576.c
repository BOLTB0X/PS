// 7576 토마토
#define Max 1001
#include <stdio.h>

typedef struct {
    int y, x;
} Pos;

int fr = 0, re = 0;
Pos que[Max * Max] = {0, };
int board[Max][Max];

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int check(int n, int m, int y, int x) {
    return 0 <= y && 0 <= x && y < n && x < m;
}

void BFS(int n, int m) {
    while (fr < re) {
        Pos cur = que[fr];
        fr++;

        for (int dir = 0; dir < 4; ++dir) {
            int ny = cur.y + dy[dir];
            int nx = cur.x + dx[dir];

            if (check(n, m, ny, nx) == 1 && board[ny][nx] == 0) {
                board[ny][nx] = board[cur.y][cur.x] + 1;
                Pos next;
                next.y = ny, next.x = nx;
                que[re] = next;
                re++;
            }
        }
    }
}

int main(void)
{
    int n, m, flag = 0, answer = 0;

    scanf("%d %d", &m, &n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &board[i][j]);
            if (board[i][j] == 1)
            {
                Pos TomaTo;
                TomaTo.y = i, TomaTo.x = j;
                que[re] = TomaTo;
                re++;
            }
        }
    }

    BFS(n, m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] > answer)
                answer = board[i][j];

            if (board[i][j] == 0) {
                answer = 0;
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            break;
        }
    }

    printf("%d", answer - 1);
    return 0;
}