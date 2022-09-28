// 1987 알파벳
#include <iostream>

using namespace std;

int res = -1;
string board[21];
int alp_occ[26] = {0, };

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

int all_visit(void) {
    for (int i = 0; i < 26; ++i) {
        if (alp_occ[i] == 1)
            return 0;
    }
    return 1;
}

void DFS(int R, int C, int cy, int cx, int level) {
    res = res < level ? level : res;

    for (int dir = 0; dir < 4; ++dir) {
        int ny = cy + dy[dir];
        int nx = cx + dx[dir];

        if (ny < 0 || nx < 0 || ny >= R | nx >= C)
            continue;

        if (alp_occ[board[ny][nx] - 'A'] == 0)
            continue;

        alp_occ[board[ny][nx] - 'A'] = 0;
        DFS(R, C, ny, nx, level + 1);
        alp_occ[board[ny][nx] - 'A'] = 1;
    }
}

int main(void) {
    int R, C;

    cin >> R >> C;
    for (int i = 0; i < R; ++i) {
        cin >> board[i];
        for (int j = 0; j < C; ++j) {
            alp_occ[board[i][j] - 'A'] = 1;
        }
    }

    alp_occ[board[0][0] - 'A'] = 0;
    DFS(R, C, 0 ,0, 1);

    cout << res;
    return 0;
}