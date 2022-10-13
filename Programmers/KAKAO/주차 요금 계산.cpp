// 2022 KAKAO BLIND RECRUITMENT level2
#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

int get_tot_fee(int tot, vector<int> fees) {
    // 기본 요금 안이면
    if (tot <= fees[0]) {
        return fees[1];
    }
    
    else {
        // 소수점이 있는 경우
        if ((tot - fees[0]) % fees[2]) {
            return fees[1] + ((int)(tot - fees[0]) / fees[2] + 1) * fees[3];
        }   
        else {
            return fees[1] + ((int)(tot - fees[0]) / fees[2]) * fees[3];
        }
    }
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, vector<string>> hash; // 자동정렬을 위해
    
    for (auto record : records) {
        stringstream sstr(record);
        string time, number, state;
        
        sstr >> time >> number >> state;
        hash[number].push_back(time);
    }
    
    for (auto h : hash) {
        // 입출입이 홀수 이면
        if (h.second.size() % 2) {
            h.second.push_back("23:59");
        }
        
        int tot = 0, in_h, in_m, out_h, out_m;
        for (int i = 0; i < h.second.size(); ++i) {
            string car = h.second[i];
            // 0 ,2 ,4 in, 1, 3, 5 out
            if (i % 2) {
                out_h = stoi(car.substr(0, 2));
                out_m = stoi(car.substr(3, 2));
                
                if (out_m < in_m) {
                    tot += ((out_h - in_h - 1) * 60 + (60 + out_m - in_m));
                }
                
                else {
                    tot += ((out_h - in_h) * 60 + (out_m - in_m));
                }
            }
            
            else {
                in_h = stoi(car.substr(0, 2));
                in_m = stoi(car.substr(3, 2));
            }
        }
        
        answer.push_back(get_tot_fee(tot, fees));
    }
    
    return answer;
}