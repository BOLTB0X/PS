// 2046 숫자사각형 4
#include <cstdio>

int board[110][110] = {0,};

void make_shape(int n, int m) {
    int number = 1;
    if (m == 1) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                board[i][j] = number;
            }
            number++;
        }
    }

    else if (m == 2) {
        for (int i = 1; i <= n; ++i) {
            if (i % 2) {
                for (int j = 1; j <= n; ++j) {
                    board[i][j] = number++;
                    if (j == n)
                        number--;
                }

            }
            else {
                for (int j = 1; j <= n; ++j) {
                    board[i][j] = number--;
                    if (j == n)
                        number++;
                }
            }
        }
    }

    else {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1, num = i; j <= n; ++j, num += i) {
                board[i][j] = num;
            }
        }   
    }

    return;
}

int main(void) {
    int n, m;

    scanf("%d %d", &n, &m);
    make_shape(n,m);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}