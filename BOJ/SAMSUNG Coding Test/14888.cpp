// 14888 연산자 끼워넣기
#define LL long long
#include <iostream>
#include <vector>

using namespace std;

void DFS(int n, vector<int> arr, int plus, int minus, int multi, int div, LL tot, int level, vector<LL> &answer)
{
    if (level == n)
    {
        if (answer[0] < tot)
            answer[0] = tot;
        if (answer[1] > tot)
            answer[1] = tot;
        return;
    }

    else {
        if (plus > 0)
        {
            DFS(n, arr, plus - 1, minus, multi, div, tot + arr[level], level + 1, answer);
        }

        if (minus > 0)
        {
            DFS(n, arr, plus, minus - 1, multi, div, tot - arr[level], level + 1, answer);
        }

        if (multi > 0)
        {
            DFS(n, arr, plus, minus, multi - 1, div, tot * arr[level], level + 1, answer);
        }

        if (div > 0)
        {
            DFS(n, arr, plus, minus, multi, div - 1, (LL)tot / arr[level], level + 1, answer);
        }
    }
}

vector<LL> solution(int n, vector<int> arr, int plus, int minus, int multi, int div)
{
    vector<LL> answer(2, 0);

    answer[0] = -2e9, answer[1] = 2e9;
    DFS(n, arr, plus, minus, multi, div, arr[0], 1, answer);

    return answer;
}

int main(void)
{
    int n;
    vector<int> arr;
    int plus, minus, multi, div;

    cin >> n;
    arr = vector<int>(n, 0);

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cin >> plus >> minus >> multi >> div;

    vector<LL> ret = solution(n, arr, plus, minus, multi, div);
    cout << ret[0] << '\n';
    cout << ret[1];
    return 0;
}