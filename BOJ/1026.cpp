// 1026 보물
#define LL long long
#include <iostream>
#include <algorithm>

using namespace std;

int a[100], b[100];

LL solution(int n) {
    LL answer = 0;
    bool check[100] = {0, };

    sort(a, a + n); // 오름차순

    // 그리디
    for (int i = 0; i < n; ++i) {
        int max = 0;
        int max_idx = 0;
        for (int j = 0; j < n; ++j) {
            if (max < b[j] && !check[j]) {
                max = b[j];
                max_idx = j;
            }
        }

        check[max_idx] = true;
        answer += (a[i] * max);
    }
    
    return answer;
}

int main(void) {
    int n;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    LL ret = solution(n);
    cout << ret;
    return 0;
}