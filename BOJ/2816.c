#include <stdio.h>
#include <string.h>

int main(void)
{
    int n, k1, k2;
    char str[101][11] = {'\0', };

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", str[i]);

        if (strcmp(str[i], "KBS1") == 0) {
            k1 = i;
        }

        else if (strcmp(str[i], "KBS2") == 0) {
            k2 = i;
        }
    }

    int idx = k1;
    for (int i = 0; i < idx; ++i) {
        printf("1");
    }

    for (int i = 0; i < idx; ++i) {
        printf("4");
    }

    if (k1 > k2) {
        k2++;
    }

    idx = k2 ;
    for (int i = 0; i < idx; ++i) {
        printf("1");
    }

    for (int i = 0; i < idx - 1; ++i) {
        printf("4");
    }
    return 0;
}