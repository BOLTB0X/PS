// 1856 숫자사각형2
#include <cstdio>

int board[110][110] = {0,};

int main(void) {
    int n, m;

    scanf("%d %d", &n, &m);

    int number = 1;
    for (int i = 1; i <= n; ++i) {
        if (i % 2) {
            for (int j = 1; j <= m; ++j) {
                // 홀수
                board[i][j] = number++;   
            }   
        }
        else{
            for (int j = m; j >= 1; --j) {
                // 홀수
                board[i][j] = number++;   
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}