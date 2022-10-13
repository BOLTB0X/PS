// 1764 듣보잡
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main(void) {
    int n, m;
    string str;
    map<string, int> hash;
    vector<string> answer;

    cin >> n >> m;
    for (int i = 0; i < n + m; ++i) {
        cin >> str;
        hash[str]++;
    }

    for (auto h : hash) {
        if (h.second > 1) {
            answer.push_back(h.first);
        }
    }

    cout << answer.size() << '\n';
    for (auto a : answer)
        cout << a << '\n';
    return 0;
}