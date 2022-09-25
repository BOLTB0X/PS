// 7562 나이트의 이동
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int board[300][300];
int visited[300][300];

const int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int BFS(int n, int sy, int sx, int ey, int ex) {
    queue<pair<int, int>> que;
    que.push({sy, sx});
    visited[sy][sx] = 1;

    while (!que.empty()) {
        int cy = que.front().first;
        int cx = que.front().second;
        que.pop();

        if (cy == ey && ex == cx) {
            break;
        }

        for (int dir = 0; dir < 8; ++dir) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 0 || nx < 0 || ny >= n || nx >= n)
                continue;

            if (visited[ny][nx] != 0) 
                continue;

            visited[ny][nx] = visited[cy][cx] + 1;
            que.push({ny, nx});
        }
    }

    return visited[ey][ex] - 1;
}

int main(void) {
    int T, n, sy, sx, ey, ex;

    cin >> T;
    while (T--) {
        cin >> n;

        memset(visited, 0, sizeof(visited));
        cin >> sy >> sx;
        cin >> ey >> ex;

        if (sy == ey && sx == ex)
            cout << "0" << '\n';

        else {
            int ret = BFS(n, sy, sx, ey, ex);
            cout << ret << '\n';
        }
    }
    return 0;
}