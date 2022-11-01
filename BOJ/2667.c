// 2667 단지번호붙이기
#include <stdio.h>
#include <stdlib.h>

int ans_idx = 0;
int answer[26 * 26] = {0, };
int cnt = 0;
int board[26][26];
int visited[26][26] = {0, };

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

int compare(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

void DFS(int n, int y, int x) {
    visited[y][x] = 1;
    cnt++;

    for (int dir = 0; dir < 4; ++dir) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if (ny < 0 || nx < 0 || ny >= n || nx >= n) {
            continue;
        }

        if (visited[ny][nx] == 1 || board[ny][nx] == 0) {
            continue;
        }

        DFS(n, ny, nx);
    }

    return;
}

void solution(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (visited[i][j] == 0 && board[i][j] == 1) {
                cnt = 0;
                DFS(n, i, j);
                answer[ans_idx++] = cnt;
            }        
        }
    }

    qsort(answer, ans_idx, sizeof(int), compare);

    return;
}

int main(void) {   
    int n;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%1d", &board[i][j]);   
        }
    }

    solution(n);

    printf("%d\n", ans_idx);
    for (int i = 0; i < ans_idx; ++i) {
        printf("%d ", answer[i]);
    }

    return 0;
}