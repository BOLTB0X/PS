// 1205 등수 구하기
#define LL long long
#include <iostream>

using namespace std;

LL arr[50];

int main(void) {
    LL answer= 1;
    LL n, cur_score, p, cnt;

    cin >> n >> cur_score >> p;
    for (LL i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    for (LL i = 0; i < n; ++i) {
        if (arr[i] > cur_score) {
            cnt++;
        }

    }

    cout << answer;
    return 0;
}