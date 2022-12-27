// 21921 블로그
#define LL long long
#include <iostream>
#include <vector>

using namespace std;

pair<LL, LL> solution(int n, int x, vector<int> visiter) {
    pair<LL, LL> answer;
    LL tot = 0;

    for (int i = 0; i < x; ++i)
        tot += visiter[i];

    for ()
    return answer;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, x;
    vector<int> visiter;

    cin >> n >> x;
    visiter = vector<int> (n, 0);

    for (int i = 0; i < n; ++i) {
        cin >> visiter[i];    
    }

    pair<LL, LL> ret = solution(n, x, visiter);
    cout << ret.first << '\n' << ret.second;
    return 0;
}