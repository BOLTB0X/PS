// 2022 KAKAO BLIND RECRUITMENT level 2
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <cmath>

using namespace std;

int get_fee(int tot, vector<int> fees) {
    int ret = 0;
    
    if (tot <= fees[0])
        ret = fees[1];
    
    else {
        ret = fees[1] + ceil((double)(tot - fees[0])/fees[2]) * fees[3];
    }
    
    return ret;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, vector<string>> records_m; 
    
    for (auto record : records) {
        stringstream sstr(record);
        string time, number, state;
        
        sstr >> time >> number >> state;
        
        records_m[number].push_back(time);
    }
    
    for (auto& iter : records_m) {
        // 홀수 면
        if (iter.second.size() % 2)
            iter.second.push_back("23:59");
        
        int in_h = 0, out_h = 0, in_m = 0, out_m = 0, tot = 0;
        // 해당 번호 차량 입출입 확인
        for (int i = 0; i < iter.second.size(); ++i) {
            string time = iter.second[i];
            if (i % 2 == 0) {
                in_h = stoi(time.substr(0, 2));
                in_m = stoi(time.substr(3, 2));
            }
            
            else {
                out_h = stoi(time.substr(0, 2));
                out_m = stoi(time.substr(3, 2));
                
                int h = out_h - in_h;
                int m = out_m - in_m;
                
                if (m < 0) {
                    m += 60;
                    h--;
                }
                
                tot += h * 60 + m;
            }
        }
            
        answer.push_back(get_fee(tot, fees));
    }
    
    return answer;
}