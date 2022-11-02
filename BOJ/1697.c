// 1697 숨바꼭질
#define Max 100001
#include <stdio.h>

int visited[Max * 2] = {0, } ;
int que[Max];
int fr = 0, re = 0;

int BFS(int n, int k) {
    que[re++] = n;
    visited[n] = 1;
    
    while (fr < re)
    {
        int cur = que[fr++];

        if (cur == k)
        {
            return visited[cur] - 1;
        }

        if (cur + 1 < Max && visited[cur + 1] == 0)
        {
            visited[cur + 1] = visited[cur] + 1;
            que[re++] = cur + 1;
        }

        if (cur * 2 < Max && visited[cur * 2] == 0)
        {
            visited[cur * 2] = visited[cur] + 1;
            que[re++] = cur * 2;
        }

        if (cur - 1 >= 0 && visited[cur - 1] == 0)
        {
            visited[cur - 1] = visited[cur] + 1;
            que[re++] = cur - 1;
        }
    }
    
}

int main(void) {
    int n, k;

    scanf("%d %d", &n, &k);
    
    int ret = BFS(n, k);
    printf("%d", ret);
    return 0;
}