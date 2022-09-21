// 10828 스택
#include <stdio.h>
#include <string.h>

int stack[10001];
int top = -1;

int main(void)
{
    int T;

    scanf("%d", &T);
    while (T--)
    {
        char cmd[10] = {'\0', };
        int data;

        scanf("%s", cmd);

        if (strcmp(cmd, "push") == 0)
        {
            scanf("%d", &data);
            stack[++top] = data;
        }

        else if (strcmp(cmd, "top") == 0)
        {
            if (top != -1)
                printf("%d\n", stack[top]);
            else
                printf("-1\n");
        }

        else if (strcmp(cmd, "size") == 0)
        {
            if (top == -1)
                printf("0\n");
            else
                printf("%d\n", top + 1);
        }

        else if (strcmp(cmd, "empty") == 0)
        {
            if (top == -1)
                printf("1\n");
            else
                printf("0\n");
        }

        else if (strcmp(cmd, "pop") == 0)
        {   
            if (top != -1)
                printf("%d\n", stack[top--]);
            else
                printf("-1\n");
        }
    }
    
    return 0;
}