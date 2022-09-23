// 9093 단어 뒤집기
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void) {
    int T;
    string str;
    stack<char> st;

    cin >> T;
    cin.ignore();
    while (T--) {
        getline(cin, str);
        str += ' ';

        for (int i = 0; i < str.length(); ++i) {
            if (str[i] == ' ') {
                while (!st.empty())
                {
                    cout << st.top();
                    st.pop();
                }
                cout << ' ';
            }
            else
                st.push(str[i]);
        }
    }
    return 0;
}