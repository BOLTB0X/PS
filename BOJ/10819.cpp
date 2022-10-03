// 10819 차이를 최대로
#include <iostream>
#include <vector>

using namespace std;

int n;
int arr[8];
int visited[8];
int res = -1;

int Abs(int a) {
    return a < 0 ? -a : a;
}

int Max(int a, int b) {
    return a > b ? a : b;
}

void DFS(vector<int>& per, int level) {
    if (level == n) {
        int tmp = 0;
        for (int i = 0; i < n - 1; ++i) {
            tmp += Abs(per[i] - per[i + 1]);
        }

        res = Max(res, tmp);
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (visited[i] == 1)
            continue;
        visited[i] = 1;
        per.push_back(arr[i]);
        DFS(per, level + 1);
        visited[i] = 0;
        per.pop_back();
    }

    return;
}

int main(void) {
    cin >> n;
    vector<int> per;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    DFS(per, 0);
    cout << res;
    return 0;
}