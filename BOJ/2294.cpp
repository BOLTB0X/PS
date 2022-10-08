// 2294 동전 2
#include <iostream>

using namespace std;

int dp[100010];

int min(int a, int b) {
    return a < b ? a : b;
}

int solution(int n, int k, int* coins) {
    int answer = 0;

    for (int i = 1; i <= k; ++i) {
        dp[i] = 2e9;
    }

    for (int i = 0; i < n; ++i) {
        dp[coins[i]] = 1;
    }

    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = coins[i]; j <= k; ++j) {
            dp[j] = min(dp[j] ,dp[j - coins[i]] + 1);
        }
    }

    if (dp[k] == 2e9)
        answer = -1;
    else
        answer = dp[k];
    return answer;
}

int main(void) {
    int n, k;
    int coins[100];

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    int ret = solution(n, k, coins);
    cout << ret;
    return 0;
}