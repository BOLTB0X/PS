// 2309 일곱 난쟁이
#include <stdio.h>
#include <stdlib.h>

int arr[9];

int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int arr_sum(void) {
    int tot = 0;
    for (int i = 0; i < 9; ++i) {
        tot += arr[i];
    }

    return tot;
}


int main(void) {
    int flag = 0;

    for (int i = 0; i < 9; ++i) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < 8; ++i) {
        for (int j = i + 1; j < 9; ++j) {
            if (arr_sum() - arr[i] - arr[j] == 100) {
                arr[i] = -1;
                arr[j] = -1;
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            break;
    }

    qsort(arr, 9, sizeof(int), compare);
    for (int i = 0; i < 9; ++i) {
        if (arr[i] == -1)
            continue;
        printf("%d\n", arr[i]);
    }
    return 0;
}