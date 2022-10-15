// 2529 부등호
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string per;
int visited[10] = {0, };

bool check(int n, vector<char>& v) {
    for (int i = 0; i < per.size() - 1; ++i) {
        if (v[i] == '<' && (per[i] - '0' > per[i + 1] - '0'))
            return false;
        if (v[i] == '>' && (per[i] - '0' < per[i + 1] - '0'))
            return false;
    }

    return true;
}

void DFS(int n, vector<char> v, pair<string, string>& answer, int level) {
    if (level == n + 1) {
        if (check(n, v)) {
            answer.first = stoll(per) > stoll(answer.first) ? per : answer.first;
            answer.second = stoll(per) < stoll(answer.second) ? per : answer.second;
        }
        return;
    }

    for (int i = 0; i < 10; ++i) {
        if (visited[i] == 1)
            continue;

        if (per.size() < 2) {
            per.push_back(i + '0');
            visited[i] = 1;
            DFS(n, v, answer, level + 1);
            visited[i] = 0;
            per.pop_back();
        }

        else {
            if (check(n, v)) {
                per.push_back(i + '0');
                visited[i] = 1;
                DFS(n, v, answer, level + 1);
                visited[i] = 0;
                per.pop_back();
            }
        }
    }
}

pair<string, string> solution(int n, vector<char> v) {
    pair<string, string> answer;

    answer.first = "-1", answer.second = "9999999999";
    DFS(n, v, answer, 0);
    return answer;
}

int main(void) 
{
    int n;
    vector<char> v;

    cin >> n;
    v = vector<char> (n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    pair<string, string> ret = solution(n, v);
    cout << ret.first << '\n' << ret.second;
    return 0;
}