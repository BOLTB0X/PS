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

        while (number <= val)
        {   
            ans += "+";
            st.push(number++);
        }

        if (st.top() == val) {
            ans += "-";
            st.pop(); 
        }

        else {
            flag = 0;
            break;
        }
    }

    if (flag == 0) {
        cout << "NO";
    }

    else {
        for (char a : ans)
            cout << a << '\n';
    }
    
    return 0;
}