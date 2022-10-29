// 올림픽 8979
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> board;

/* 정렬 ver */
struct medal {
    int gold, silver, bronze;
};

bool compare(const medal &a, const medal &b) {
    if (a.gold == b.gold) {
        if (a.silver == b.silver)
            return a.bronze > b.bronze;
        return a.silver > b.silver;
    }
    return a.gold > b.gold;
}

int solution(int n, int k) {
    int answer = 0;
    int t_g, t_s, t_b;
    vector<medal> v;

    for (int i = 1; i <= n; ++i) {
        if (i == k) {
            t_g = board[k][0], t_s = board[k][1], t_b = board[k][2];
        }

        v.push_back({board[i][0], board[i][1], board[i][2]});
    }

    sort(v.begin(), v.end(), compare);

    answer = 1;
    for (auto m : v) {
        if (m.gold == t_g && m.silver == t_s && m.bronze == t_b)
            break;
        
        answer++;
    }
    
    return answer;
}
/********************/

/* 완전탐색 */
int solution2(int n, int k) {
    int answer = 1;

    for (int i = 1; i <= n; ++i) {
        if (board[k][0] < board[i][0]) {
            answer++;
        }

        if (board[k][0] == board[i][0]) {
            if (board[k][1] < board[i][1])
                answer++;
        }

        if ((board[k][0] == board[i][0]) && (board[k][1] == board[i][1])) {
            if (board[k][2] < board[i][2])
                answer++;
        }

    }

    return answer;
}
/*******************/

int main(void) {
    int n, k, tmp, ans = 1;

    cin >> n >> k;
    board = vector<vector<int>> (n + 1, vector<int> (3));

    for (int i = 0; i < n; ++i) {
        cin >> tmp;

        for (int j = 0; j < 3; ++j) {
            cin >> board[tmp][j];
        }
    }

    int ret = solution2(n, k);
    cout << ret;
    return 0;
}