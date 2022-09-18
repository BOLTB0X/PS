// 1747 소수&팰린드롬
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
        
        for (int j = 2 * i; j <= Max_Len ; j += i)
        {
            prime[j] = 1;
        } 
    }
    return;
}

int is_Pallin(char* str)
{
    int len = strlen(str);

    for (int i = 0; i < len; ++i)
    {
        // 체크
        if (str[i] != str[len - 1 - i])
        {
            return 0;
        }
    }

    return 1;
}

int main(void)
{
    int n;
    char str[10] = {'\0', };

    scanf("%d", &n);
    eratos(); // 소수 체크

    for (int i = n; i < Max_Len; ++i)
    {
        sprintf(str, "%d", i); // 문자열 변환
        if (prime[i] == 0 && is_Pallin(str))
        {
            printf("%d", i); 
            break; // 가장 작은 수 
        }
    }
    return 0;
}