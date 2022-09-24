// 1652 누울 자리를 찾아라
#include <stdio.h>
#include <string.h>

char board[101][101];

int main(void) {
    int n, check = 0, ans1 = 0, ans2 = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", board[i]);
    }

    // 가로
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == '.') {
                check++;
            }

            else
            {
                if (check >= 2) {
                    ans1++;
                    check = 0;
                }
            }
        }
        if (check >= 2) {
            ans1++;
        }
        check = 0;
    }

    // 세로
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[j][i] == '.') {
                check++;
            }

            else
            {
                if (check >= 2) {
                    ans2++;
                }
                check = 0;
            }
        }
        if (check >= 2) {
            ans2++;
        }
        check = 0;
    }

    printf("%d %d", ans1, ans2);
    return 0;
}