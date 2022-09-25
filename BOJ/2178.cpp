// 미로 탐색 2178
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<string> board;
vector<vector<int>> dist;

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

void BFS(void) {
    queue<pair<int, int>> que;
    que.push({0, 0});
    dist[0][0] = 1;

    while ((!que.empty())) {
        int cy = que.front().first;
        int cx = que.front().second;
        que.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                continue;
            
            if (dist[ny][nx] != 0 || board[ny][nx] == '0')
                continue;

            dist[ny][nx] = dist[cy][cx] + 1;
            que.push({ny, nx});
        }
    }
    
    return;
}

int main(void) {
    string str;
    cin >> n >> m;

    board.resize(n);
    dist.resize(n, vector<int> (m, 0));

    for (int i = 0; i < n; ++i) {
        cin >> board[i];
    }

    BFS();
    cout << dist[n - 1][m - 1];
    return 0;
}