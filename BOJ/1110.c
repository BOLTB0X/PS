// 1110 더하기 싸이클 
#include <stdio.h>

int main(void) {
    int num, tmp, ans = 0;

    scanf("%d", &num);
    tmp = num;
    
    while (1) {
        int front = tmp / 10;
        int back = tmp % 10;

        int new_num = (back * 10) + ((front + back) % 10);
        ans++;

        if (new_num == num) {
            break;
        }

        else {
            tmp = new_num;
        }
    }
    
    printf("%d", ans);
    return 0;
}