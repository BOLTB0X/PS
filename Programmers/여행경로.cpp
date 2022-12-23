#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> path;
int visited[10000] = {0, };

bool DFS(vector<vector<string>> tickets, string cur, int depth) {
    if (depth == tickets.size())
        return true;
    
    for (int i = 0; i < tickets.size(); ++i) {
        // 미방문이고 다음 행선지이면
        if (visited[i] == 0 && cur == tickets[i][0]) {
            visited[i] = 1;
            path.push_back(tickets[i][1]);
            bool check = DFS(tickets, tickets[i][1], depth + 1);
            
            // 다 돈 경우
            if (check)
                return true;
            // 끊긴 경우
            visited[i] = 0;
        }
    }
    
    // 끊긴 경우
    path.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    // 알파벳 순을 위한 정렬
    sort(tickets.begin(), tickets.end());
    
    path.push_back("ICN");
    DFS(tickets, "ICN", 0);
    
    answer = path;
    return answer;
}