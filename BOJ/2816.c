// 2816 디지털 티비
#include <stdio.h>
#include <string.h>

int main(void) {
    int n, k_idx1, k_idx2;
    char board[101][11];

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", board[i]);

        if (strcmp(board[i], "KBS1") == 0) {
            k_idx1 = i;
        }

        else if (strcmp(board[i], "KBS2") == 0) {
            k_idx2 = i;
        }
    }

    for (int i = 0; i < k_idx1; ++i) {
        printf("1");
    }
    
    for (int i = 0; i < k_idx1; ++i) {
        printf("4");
    }

    if (k_idx1 > k_idx2)
        k_idx2++;
        for (int i = 0; i < k_idx2; ++i) {
        printf("1");
    }
    
    for (int i = 0; i < k_idx2 - 1; ++i) {
        printf("4");
    }

    return 0;
}