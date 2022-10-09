// 2022 KAKAO BLIND RECURITMENT level 1
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    
    // 신고자 횟수
    unordered_map<string, int> id_cnt;
    
    // 신고 하는 자 -> 신고 받는자
    unordered_map<string, set<string>> id_report;
    
    for (int i = 0; i < id_list.size(); ++i) {
        id_cnt.insert({id_list[i], i});
    }
    
    for (auto r : report) {
        stringstream sstr(r);
        string front, back;
        
        sstr >> front >> back;
        
        id_report[back].insert(front);
    }
    
    for (auto id_r : id_report) {
        // 신고 누적이 k면
        if (id_r.second.size() >= k) {
            for (auto i : id_r.second) {
                answer[id_cnt[i]]++;
            }
        }
    }
    
    return answer;
}