// 1931 회의실 배정
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comapre(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int solution(int n, vector<pair<int,int>> v) {
    int answer = 1;

    sort(v.begin(), v.end(), comapre);
    int standard = v[0].second;

    for (int i = 1; i < v.size(); ++i) {
        // 시작 시간과 끝나는 시간 비교
        if (standard <= v[i].first) {
            answer++;
            standard = v[i].second;
        }
    }
    return answer;
}

int main(void) {
    int n, answer;
    vector<pair<int,int>> v;

    cin >> n;
    v = vector<pair<int,int>>(n, {0, 0});

    for (int i = 0; i < n; ++i) 
    {
        cin >> v[i].first >> v[i].second;
    }

    answer = solution(n, v);
    cout << answer;
    return 0;
}