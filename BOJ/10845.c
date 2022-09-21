// 10845 큐
#include <stdio.h>
#include <string.h>

int fr = 0, re = 0;
int que[10001] = {0, };

int main(void)
{
    int T;

    scanf("%d", &T);

    while (T--)
    {
        int data;
        char cmd[10];

        scanf("%s", cmd);
        if (strcmp(cmd, "push") == 0)
        {
            scanf("%d", &data);
            que[re++] = data;
        }

        else if (strcmp(cmd, "front") == 0)
        {
            if (fr < re)
                printf("%d\n", que[fr]);
            else
                printf("-1\n");
        }

        else if (strcmp(cmd, "back") == 0)
        {
            if (fr < re)
                printf("%d\n", que[re - 1]);
            else
                printf("-1\n");
        }
        else if (strcmp(cmd, "size") == 0)
        {
            printf("%d\n", re - fr);
        }

        else if (strcmp(cmd, "empty") == 0)
        {
            if (fr == re)
                printf("1\n");
            else
                printf("0\n");
        }

        else if (strcmp(cmd, "pop") == 0)
        {   
            if (fr < re)
                printf("%d\n", que[fr++]);
            else
                printf("-1\n");
        }
    }
}