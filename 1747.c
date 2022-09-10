#include <stdio.h>
#include <string.h>
#define Max_Len 1500001

int prime[Max_Len + 10] = {0, };

// 소수 체크
void eratos(void) 
{
    prime[0] = prime[1] = 1;
    for (int i = 2; i <= Max_Len; ++i)
    {
        if (prime[i] != 0)
        {
            continue;
        }
        
        for (int j = i; j <= Max_Len / i ; j++)
        {
            prime[i * j] = 1;
        } 
    }
    return;
}

int is_Palin(char* str)
{
    int len  = strlen(str), flag = 1;

    for (int i = 0; i < len; ++i)
    {
        if (str[i] != str[len - 1 - i])
        {
            flag = 0;
            break;
        }
    }

    if (flag == 0)
    {
        return 0;
    }
    else 
    {
        return 1;
    }
}

int main(void)
{
    int n;
    char str[10] = {'\0', };


    scanf("%d", &n);

    eratos(); // 소수 체크
    
    for (int i = n; i <= Max_Len; ++i)
    {
        sprintf(str, "%d", i);
        if (prime[i] == 0 && is_Palin(str))
        {
            printf("%d", i);
            break;
        }
    }

    return 0;
}