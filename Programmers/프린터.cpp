//level 2
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int> pq;
    queue<pair<int,int>> q;
    
    for (int i = 0; i < priorities.size(); ++i) {
        q.push({i, priorities[i]});
        pq.push(priorities[i]);
    }
    
    while (!q.empty()) {
        pair<int,int> cur = q.front();
        q.pop();
        
        if (cur.second == pq.top()) {
            answer++;
            pq.pop();
            if (cur.first == location) {        
                break;
            }
            
        }
        else
            q.push(cur);
    }
    
    return answer;
}