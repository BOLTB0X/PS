#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    // 힙을 사용할 우선순위 큐
    priority_queue <int, vector<int>, greater<int> > pq;
    
    for (auto& sco : scoville) {
        pq.push(sco);
    }
    
    // 힙안에 가장 작은 원소가 첫번째 임으로
    // 반복문 조건을 pq.top() < k 
    while (pq.top() < K && pq.size() > 1) {
        answer++; // 카운트
        
        int fir = pq.top();
        pq.pop();
        int sec = pq.top();
        pq.pop();
        
        pq.push(fir + (sec * 2));
    }
    
    // 안나올 경우
    if (pq.top() < K)
        answer = -1;
    return answer;
}