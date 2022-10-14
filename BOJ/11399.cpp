// 11399 ATM
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int *arr) {
    int answer = 0;
    vector<int> dp(n, 0);

    sort(arr, arr + n);
    dp[0] = arr[0];
    answer = arr[0];

    for (int i = 1; i < n; ++i) {
        dp[i] = dp[i - 1] + arr[i];
        answer += dp[i];
    }

    return answer;
}

int main(void) {
    int n;
    int arr[1000];

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int ret = solution(n, arr);
    cout << ret;

    return 0;
}