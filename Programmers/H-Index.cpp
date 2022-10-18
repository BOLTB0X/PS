// level 2
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int compare(int a, int b) {
    return a > b;
}

int solution(vector<int> citations) {
    int answer = 0;
    int size = citations.size();
    
    sort(citations.begin(), citations.end(), compare);
    
    for (int i = 0; i < size; ++i) {
        if (citations[i] > i)
            answer++;
        else
        {
            break;    
        }
    }
    
    return answer;
}