//level 3
#include <string>
#include <vector>
#include <queue>

using namespace std;

int board[110][110];
const int dy[4] = {-1,1,0,0};
const int dx[4] = {0,0,-1,1};

// 생성
void create_board(vector<vector<int>>& rectangle) {
    for (int i = 0; i < rectangle.size(); ++i) {
        for (int j = 0; j < rectangle[i].size(); ++j) {
            rectangle[i][j] *= 2;
        }

        // 맵 생성
        for (int j = rectangle[i][1]; j < rectangle[i][3]; ++j) {
            for (int k = rectangle[i][0]; k < rectangle[i][2]; ++k)
                board[j][k] = 1;
        }
    }

    // 안쪽 맵 0 처리
    for (int i = 0; i < rectangle.size(); ++i) {
        for (int j = rectangle[i][1] + 1; j < rectangle[i][3]; ++j) {
            for (int k = rectangle[i][0] + 1; k < rectangle[i][2]; ++k)
                board[j][k] = 0;
        }
    }
}

//BFS
int BFS(int cy, int cx, int iy, int ix) {
    int visited[110][110] = {0, };
    int result = 0;
    queue<pair<int, int>> que;

    visited[cy][cx] = 1;
    que.push({cy, cx});

    while(!que.empty()) {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        if (y == iy && x == ix) {
            result = visited[y][x];
            break;
        }

        for (int dir = 0; dir <4; ++dir) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            // 테두리이고 미방문인 경우
            if (board[ny][nx] == 1 && visited[ny][nx] == 0) {
                visited[ny][nx] = visited[y][x] + 1;
                que.push({ny, nx});
            }
        }
    }

    return result;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;

    create_board(rectangle);
    answer = BFS(characterY * 2, characterX * 2, itemY * 2, itemX * 2);
    return answer;
}