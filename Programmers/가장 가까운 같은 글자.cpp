// level 1
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    string pre_s = "";
    int alp_occ[26] = {0, }; // 나왔는지 안나왔는지
    
    for (int i = 0; i < s.size(); ++i) {
        // 방문 했다면
        if (alp_occ[s[i] - 'a'] == 1) {
            for (int j = pre_s.size() - 1; j >= 0; --j) {
                // 찾는 다면
                if (s[i] == pre_s[j]) {
                    answer.push_back(i - j);
                    break;
                }
            }
        }

        else {
            alp_occ[s[i] - 'a'] = 1;
            answer.push_back(-1);
        }
        // 현재 문자 
        pre_s += s[i];
    }
    return answer;
}