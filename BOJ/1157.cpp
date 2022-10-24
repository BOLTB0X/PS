// 1157 단어 공부
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string input;
    int max_cnt = 0;
    int alp[26] = {0, };
    char answer;

    cin >> input;

    for (int i = 0; i < input.length(); ++i) {
        if (input[i] >= 'a')
            alp[input[i] - 'a']++;
        else
            alp[input[i] - 'A']++;
    }

    for (int i = 0; i < 26; ++i) {
        if (alp[i] > max_cnt) {
            max_cnt = alp[i];
            answer = i + 'A';
        }

        else if (max_cnt == alp[i])
            answer = -1;
    }

    if (answer == -1)
        cout << "?";
    else {
        cout << answer;
    }

    return 0;
}