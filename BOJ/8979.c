// 8979 올림픽
#include <stdio.h>

int arr[1001][4];

int main(void)
{
    int n, k, tmp, ans = 1;

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &tmp);
        for (int j = 1; j <= 3; ++j) {
            scanf("%d", &arr[tmp][j]);
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (arr[k][1] < arr[i][1]) {
            ans++;
        }

        if (arr[k][1] == arr[i][1] && arr[k][2] < arr[i][2]) {
            ans++;
        }

        if (arr[k][1] == arr[i][1] && arr[k][2] == arr[i][2] && 
        arr[k][3] < arr[i][3]) {
            ans++;
        }
    }

    printf("%d", ans);
    return 0;
}