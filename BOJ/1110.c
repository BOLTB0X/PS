// 1110 더하기 사이클
#include <stdio.h>

int solution(int n) {
    int answer = 0;

    int number = n, new_number = 0;

    while (1) {
        int front = number / 10;
        int back = number % 10;

        new_number = back * 10 + ((front + back) % 10);
        answer++;

        if (new_number == n)
            break;
        
        number = new_number;
    }
    return answer;
}

int main(void) {
    int n;

    scanf("%d", &n);

    int ret = solution(n);
    printf("%d", ret);

    return 0;
}