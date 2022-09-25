// 9012 괄호
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void) {
    int T;
    string cmd;

    cin >> T;

    while (T--) {
        stack<char> paren;
        int flag = 0;
        cin >> cmd;

        for (int i = 0; i < cmd.length(); ++i) {
            if (cmd[i] == '(')
                paren.push('(');
            
            else {
                if (paren.empty()) {
                    cout << "NO\n";
                    flag = 1;
                    break;
                }

                else if (paren.top() == '(') {
                    paren.pop();
                }
            }
        }

        if (!paren.empty()) {
            cout << "NO\n";
        }
        else if (flag == 0)
            cout << "YES\n";
    }
    return 0;
}