// 맥주 마시면서 걸어가기
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int,int>> store;
vector<int> visited;

const int dy[4] = {-1,1,0,0};
const int dx[4] = {0,0,-1,1};

int abs(int a) {
    return a < 0 ? -a : a;
}

string BFS(int n, int sy, int sx, int ey, int ex) {
    string ret = "sad";

    queue<pair<int,int>> que;
    que.push({sy, sx});

    while (!que.empty()) {
        pair<int,int> cur = que.front();
        que.pop();
        
        if (abs(ey - cur.first) + abs(ex - cur.second) <= 1000) {
            ret = "happy";
            break;
        }

        for (int i = 0; i < n; ++i) {
            int store_y = store[i].first;
            int store_x = store[i].second;

            if (abs(store_y - cur.first) + abs(store_x - cur.second) <= 1000 && visited[i] == 0) {
                visited[i] = 1;
                que.push({store_y, store_x});
            }
        }
    }
    
    return ret;
}

int main(void) {
    int T, n, sy, sx, y, x, ey, ex;

    cin >> T;
    while (T--)
    {
        cin >> n;
        store = vector<pair<int,int>> (n, {0, 0});
        visited = vector<int> (n, 0);
        cin >> sy >> sx;

        for (int i = 0; i < n; ++i) {
            cin >> y >> x;
            store[i] = {y, x};
        }

        cin >> ey >> ex;

        string ret = BFS(n, sy, sx, ey, ex);
        cout << ret << '\n';
    }
    
    return 0;
}