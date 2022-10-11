// 2022 KAKAO BLIND RECRUITMENT level 2
#define LL long long
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool is_prime(LL number) {
    if (number == 0 || number == 1)
        return false;
    
    for (int i = 2; i <= (int)sqrt(number); ++i) {
        if (number % i == 0)
            return false;
    }
    
    return true;
}

string trans_number(int n, int k) {
    string ret = "";
    
    while(n > 0) {
        ret += to_string(n % k);
        n /= k;
    }
    
    return string(ret.rbegin(), ret.rend());
}

int solution(int n, int k) {
    int answer = 0;
    
    string t_n = trans_number(n, k);
    string candi = "";
    
    for (LL i = 0; i < t_n.size(); ++i) {
        if (t_n[i] == '0'&& candi.length() != 0) {
            if (is_prime(stoll(candi)))
                answer++;
            candi = "";
        }
        
        else {
            candi += t_n[i];
        }
    }
    
    if (candi.size() != 0) {
        if (is_prime(stoll(candi)))
            answer++;
        candi = "";
    }

    return answer;
}