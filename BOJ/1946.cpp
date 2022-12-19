// 1946 신입 사원
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> company) {
    int answer = 0;
    
    sort(company.begin(), company.end());
    int max_score = company[0][1];

    for (auto c: company) {
        if (max_score >= c[1]) {
            answer++;
            max_score = c[1];
        }
    }

    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T, n;
    vector<vector<int>> company;
    cin >> T;

    while (T--) {
        cin >> n;
        company = vector<vector<int>> (n, vector<int>(2, 0));
        for (int i = 0; i < n; ++i) {
            cin >> company[i][0] >> company[i][1];
        }

        int ret = solution(n, company);
        cout << ret << '\n';
    }

    return 0;
}