// level 3
#include <string>
#include <vector>

using namespace std;

int visited[210] = {0, };

void DFS(int n, vector<vector<int>> &computers, int cur) {
    visited[cur] = 1;
    
    for (int i = 0; i < n; ++i) {
        if (visited[i] == 1)
            continue;
        if (computers[cur][i] == 0)
            continue;
        
        DFS(n, computers, i);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            DFS(n, computers, i);
            answer++;
        }
    }
    
    return answer;
}