// 1449 수리공 항승
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, int l, int arr[]) {
    int answer = 0;

    sort(arr, arr + n);
    int cmp = arr[0];
    for (int i = 1; i < n; ++i) {
        if (l <= arr[i] - cmp) {
            answer++;
            cmp = arr[i];
        }
    }

    ++answer;
    return answer;
}

int main(void)
{
    int n, l;
    int arr[1001];

    cin >> n >> l;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int ret = solution(n, l, arr);
    cout << ret;
    return 0;
}