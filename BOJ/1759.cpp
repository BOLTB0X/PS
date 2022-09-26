// 1759 암호 만들기
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

char arr[16];
int visited[16] = {0, };
vector<string> v;

int check(string word) {
    int m_cnt = 0;
    int j_cnt = 0;
    for (int i = 0; i < word.length(); ++i) {
        if (word[i] == 'a' || word[i] == 'e' 
        || word[i] == 'i' || word[i] == 'o' || word[i] == 'u')
            m_cnt++;
        else
            j_cnt++;
    }

    return m_cnt >= 1 && j_cnt >= 2; 
}

void DFS(int L, int C, string word, int cur) {
    if (word.length() == L) {
        if (check(word) == 1) {
            cout << word << '\n';
        }
        return;
    }

    for (int i = cur; i < C; ++i) {
        if (visited[i] == 1)
            continue;
        visited[i] = 1;
        word.push_back(arr[i]);
        DFS(L, C, word, i);
        word.pop_back();
        visited[i] = 0;
    }
    
    return;
}

int main(void) {
    int L, C;

    cin >> L >> C;
    for (int i = 0; i < C; ++i) {
        cin >> arr[i];
    }

    sort(arr, arr + C);

    DFS(L, C, "", 0);
    return 0;
}