#include <iostream>

using namespace std;

int board[1001][3];

int main(void) {
    int n, k, tmp, ans = 1;

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;

        for (int j = 0; j < 3; ++j) {
            cin >> board[tmp][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (board[k][0] < board[i][0])
            ans++;

        if (board[k][0] == board[i][0] && board[k][1] < board[i][1])
            ans++;

        if (board[k][0] == board[i][0] 
        && board[k][1] == board[i][1]
        && board[k][2] < board[i][2])
            ans++;
    }

    cout << ans;
    return 0;
}