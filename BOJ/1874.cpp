// 1874 스택 수열
#include <iostream>
#include <stack>

using namespace std;

stack<int> st;

int main(void) {
    int n, val, number = 1, flag = 1;
    string ans = "";

    cin >> n;

    while (n--) {
        cin >> val;

        if (st.empty()) {
            for (int i = 0; i < val; ++i) {
                st.push(number++);
                ans += "+";
            }
        }

        else {
            if (number < val) {
                for (int i = 0; i < val - number; ++i) {
                    st.push(number++);
                    ans += "+";
                }
           }
        }

        if (st.top() == val) {
            st.pop();
            ans += '-';
        }

        else {
            flag = 0;
        }
    }
    
    if (flag == 0) {
        cout << "NO";
    }
    else {
        for (char a: ans)
            cout << a << '\n';
    }
    for (char a: ans)
        cout << a << '\n';

    return 0;
}