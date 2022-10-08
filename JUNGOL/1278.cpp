// 1278 배낭 채우기 2
#include <iostream>
#include <vector>

using namespace std;

int dp[1001][10001] = {0, };

int max(int a, int b) {
    return a > b ? a : b;
}

int solution(int n, int w, vector<pair<int,int>> bags) {
    int answer = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= w; ++j) {
            dp[i][j] = dp[i - 1][j];

            // 제한선이 아래인 경우
            if (bags[i].first <= j) {
                dp[i][j] = max(dp[i - 1][j - bags[i].first] + bags[i].second, dp[i - 1][j]);
            }
        }
    }

    answer = dp[n][w];
    return answer;
}

int main(void) {
    int n, w;
    vector<pair<int,int>> bags;

    cin >> n >> w;
    bags = vector<pair<int,int>> (n + 1, {0, 0});

    for (int i = 1; i <= n; ++i) {
        cin >> bags[i].first >> bags[i].second;
    }

    int ret = solution(n, w, bags);
    cout << ret;
    return 0;
}