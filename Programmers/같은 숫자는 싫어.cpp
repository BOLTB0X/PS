// level 1
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    stack<int> st;
    
    for (int a : arr) {
        if (st.empty()) {
            st.push(a);
            answer.push_back(a);
        }
        
        else {
            if (st.top() == a)
                continue;
            st.push(a);
            answer.push_back(a);
        }
    }

    return answer;
}