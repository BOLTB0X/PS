// level 2
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    return a > b;
}

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end(), compare);
    
    for (auto c: citations) {
        if (c > answer)
            answer++;
        else
            break;
    }
    return answer;
}