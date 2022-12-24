// level 1
#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    long long t_len = t.length(), p_len = p.length();
    
    for (long long i = 0; i <= t_len - p_len; ++i) {
        string tmp = t.substr(i, p_len);
    
        if (stoll(tmp) <= stoll(p)) 
            answer++;

    }
    return answer;
}