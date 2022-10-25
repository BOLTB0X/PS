// 1157 단어 공부
#include <iostream>
#include <string>

using namespace std;

char solution(string str) {
    char answer;
    int alp[26] = {0, };
    int size = str.length(), cnt = 0;

    for (int i = 0; i < size; ++i) {
        if (str[i] >= 'a') {
            str[i] -= 32;
        }

        alp[str[i] - 'A']++;
    }

    for (int i = 0; i < 26; ++i) {
        if (cnt < alp[i]) {
            cnt = alp[i];
            answer = i + 'A';
        }

        else if (cnt == alp[i]) {
            answer = '?';
        }
    }

    return answer;
}

int main(void)
{
   string str;

   cin >> str;

   char ret = solution(str);
   cout << ret;

   return 0;
}