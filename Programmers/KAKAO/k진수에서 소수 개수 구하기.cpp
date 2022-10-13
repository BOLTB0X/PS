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
    
    for (LL i = 2; i <= (LL)sqrt(number); ++i) {
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

    return string(ret.rbegin(), ret.rend());;
}

int solution(int n, int k) {
    int answer = 0;
    
    string t_n = trans_number(n, k);
    LL size = t_n.length();
    string prime = "";
    
    for (LL i = 0; i < size; ++i) {
        // 소수 체크
        if (t_n[i] == '0' && prime.length() > 0) {
            if (is_prime(stoll(prime)))
                answer++;
            prime = "";
        }
        
        else {
            prime += t_n[i];
        }
    }
    
    if (prime.length() > 0) {
        if (is_prime(stoll(prime)))
            answer++;
    }
    
    return answer;
}