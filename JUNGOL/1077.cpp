// 1077 배낭채우기
#include <iostream>
#include <vector>

using namespace std;

int n, w;
vector<pair<int,int>> bags;

int dp[10001] = {0, };

int max(int a, int b) {
    return a > b ? a : b;
}

int solution(void) {
    int answer = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = bags[i].first; j <= w; ++j) {
            if (j - bags[i].first >= 0) {
                dp[j] = max(dp[j], dp[j - bags[i].first] + bags[i].second);
            }
        }
    }
    answer = dp[w];
    return answer;
}

int main(void) {
    cin >> n >> w;
    bags = vector<pair<int,int>> (n, {0, 0});

    for (int i = 0; i < n; ++i) {
        cin >> bags[i].first >> bags[i].second;
    }

    int ret = solution();
    cout << ret;
    return 0;
}