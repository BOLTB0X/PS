// 2529 부등호
#include <iostream>
#include <string>

using namespace std;

string max_num = "-1";
string min_num = "9999999999";
int visited[10] = {0, };

int check(int n, string number, char ineq[]) {
    for (int i = 0; i < number.length() - 1; ++i) {
        if (ineq[i] == '>' && ((number[i] - '0') < (number[i + 1] - '0')))
            return 0;
        
        if (ineq[i] == '<' && ((number[i] - '0') > (number[i + 1] - '0')))
            return 0;
    }

    return 1;
}

void DFS(int n, char ineq[], string number, int level) {
    if (level == n + 1) {
        if (check(n, number, ineq)) {
            if (stoll(number) > stoll(max_num))
                max_num = number;
        
            if (stoll(number) < stoll(min_num))
                min_num = number;
        }
        return;
    }

    for (int i = 0; i < 10; ++i) {
        if (visited[i] == 1)
            continue;
        
        if (number.length() < 2) {
            number.push_back(i + '0');
            visited[i] = 1;
            DFS(n, ineq, number, level + 1);
            visited[i] = 0;
            number.pop_back();
        }

        else {
            if (check(n, number, ineq)) {
                number.push_back(i + '0');
                visited[i] = 1;
                DFS(n, ineq, number, level + 1);
                visited[i] = 0;
                number.pop_back();
            }
        }
    }

    return;
}

int main(void) {
    int n;
    char ineq[10];

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> ineq[i];
    }

    DFS(n, ineq, "", 0);

    cout << max_num << '\n';
    cout << min_num;
    return 0;
}