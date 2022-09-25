// 2589 보물섬
#define MAX 51
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

char board[MAX][MAX];
int dist[MAX][MAX] = {0, };

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

int Max(int a, int b) {
    return a > b ? a : b;
}

int BFS(int n, int m, int sy, int sx) {
    queue<pair<int,int>> que;
    int result = -1;

    que.push({sy, sx});
    dist[sy][sx] = 1;

    while (!que.empty()) {
        int cy = que.front().first;
        int cx = que.front().second;
        que.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                continue;
            
            if (board[ny][nx] == 'W' || dist[ny][nx] != 0)
                continue;
            
            dist[ny][nx] = dist[cy][cx] + 1;
            result = Max(result, dist[ny][nx]);
            que.push({ny, nx});
        }
    }

    return result - 1;
}

int main(void) {
    int n, m, ans = -1;
    string tmp;

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        for (int j = 0; j < m; ++j) {
            board[i][j] = tmp[j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == 'L') {
                memset(dist, 0, sizeof(dist));
                int ret = BFS(n, m, i, j);
                ans = Max(ans, ret);
            }
        }
    }

    cout << ans;
    return 0;
}