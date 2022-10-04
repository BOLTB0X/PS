// level 2
#include <string>
#include <vector>

using namespace std;

int visited[9] = {0, };
vector<vector<int>> per;

int max(int a, int b) {
    return a > b ? a : b; 
}

int cal_cnt(int size, int k) {
    int cnt = 0, cur = k;
    
    for (auto p : per) {
        if (p[0] <= cur && cur > 0) {
            cur -= p[1];
            cnt++;
        }
        
        else {
            break;
        }
    }
    
    return cnt;
}

void DFS(int size, int k, vector<vector<int>> &dungeons, int level, int &answer) {
    if (level == size) {
        int ret = cal_cnt(size, k);
        answer = max(answer, ret);
        return;
    }
    
    for (int i = 0; i < size; ++i) {
        if (visited[i] == 1)
            continue;
        visited[i] = 1;
        per.push_back(dungeons[i]);
        DFS(size, k, dungeons, level + 1, answer);
        per.pop_back();
        visited[i] = 0;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    int size = dungeons.size();
    
    DFS(size, k, dungeons, 0, answer);
    return answer;
}