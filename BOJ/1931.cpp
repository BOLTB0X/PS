// 1931 회의실 배정
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int solution(int n, vector<pair<int,int>> v) {
    int answer = 1;
    
    // 회의실 벡터를 끝나는 시간의 오름차순으로 정렬
    sort(v.begin(), v.end(), compare);
    int cur = v[0].second; // 현재 시간

    // 그리디 방식으로 
    for (int i = 1; i < v.size(); ++i) {
        // 다음 회의실 시작이간이 현재 회의 끝나는 시간과 같거나 늦다면
        if (cur <= v[i].first) {
            cur = v[i].second; //끝나는 시간으로
            answer++;
        }
    }
    return answer;
}

int main(void) {
    int n, answer;
    vector<pair<int,int>> v;

    cin >> n;
    v = vector<pair<int,int>>(n, {0, 0});

    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }

    answer = solution(n, v);
    cout << answer;
    return 0;
}