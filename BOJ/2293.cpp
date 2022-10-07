// 2293 동전 1
#define MAX 10001
#include <iostream>

using namespace std;

int coins[101];
int dp[MAX] = {0, };

int main(void) {
    int n, k;

    cin >> n >> k;
    for (int i = 1; i <=n; ++i) {
        cin >> coins[i];
    }

    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = coins[i]; j <=k; ++j) {
            if ((j - coins[i]) >= 0) {
                dp[j] += (dp[j - coins[i]]);
            }
        }
    }

    cout << dp[k];
    return 0;
}