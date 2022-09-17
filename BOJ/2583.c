// 2583 영역 구하기
#include <stdio.h>
#include <stdlib.h> // qsort

int cnt;
int board[101][101] = {0, };

const int dy[4] = {-1,1,0,0};
const int dx[4] = {0,0,-1,1};

int compare(const void *a, const void *b) {
    return *(int*)a - *(int*) b;
}

void DFS(int n, int m, int y, int x) {
    board[y][x] = 1;
    cnt++;
    
    for (int dir = 0; dir < 4; ++dir) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if (ny < 0 || nx < 0 || ny >= n || nx >= m) {
            continue;
        }

        if (board[ny][nx] == 1) {
            continue;
        }

        DFS(n, m, ny, nx);
    }

    return;
}

int main(void) 
{
    int ans[100] = {0, };
    int m, n, k, x1, y1, x2, y2, ans_idx = 0;

    scanf("%d %d %d", &m, &n, &k);

    for (size_t i = 0; i < k; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        for (int i = x1; i < x2;++i) {
            for (int j = y1; j < y2; ++j) {
                board[i][j] = 1;
            }
        }
    }

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            if (board[i][j] == 0) {
                cnt = 0;
                DFS(n, m, i, j);
                ans[ans_idx++] = cnt;
            }
        }
    }
    
    // 오름차순
    qsort(ans, ans_idx, sizeof(int), compare);

    printf("%d\n", ans_idx);
    for (size_t i = 0; i < ans_idx; i++) {
        printf("%d ", ans[i]);
    }
    
    return 0;
}