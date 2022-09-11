#include <stdio.h>

char board[110][110];

int main(void)
{
    int n;
    int row = 0, col = 0, cnt = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        scanf("%s", board[i]);
    }

    // 가로
    for (int i = 0; i < n; ++i)
    {
        cnt = 0;
        for (int j = 0; j < n; ++j)
        {
            if (board[i][j] == '.')
            {
                cnt++;
            }

            // 카운트 조건이 벽에 닿아야함
            else
            {
                // 누울 자리이면
                if (cnt >= 2)
                {
                    row++;
                }
                cnt = 0; 
            }
        }
        if (cnt >= 2)
        {
            row++;
        }
    }

    // 세로
    for (int i = 0; i < n; ++i)
    {
        cnt = 0;
        for (int j = 0; j < n; ++j)
        {
            if (board[j][i] == '.')
            {
                cnt++;
            }

            else
            {
                if (cnt >= 2)
                {
                    col++;
                }
                cnt = 0;
            }
        }
        if (cnt >= 2)
        {
            col++;
        }
    }

    printf("%d %d", row, col);
    return 0;
}