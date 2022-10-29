// 1747 소수&팰린드롬
#define LL long long
#define MAX 1500001 
#include <iostream>
#include <string>

using namespace std;

bool is_Pal(LL number) {
    string str = to_string(number);
    int size = str.length();

    for (int i = 0; i < size; ++i) {
        if (str[i] != str[size - 1 - i]) {
            return false;
        }
    }

    return true;
}

bool is_prime(LL number) {
    if (number == 1 || number == 0)
        return false;

   for (LL i = 2; i * i <= number; ++i) {
        if (number % i == 0)
            return false;
   }
   return true; 
}

LL solution(LL n) {
    LL answer = 0;

    for (LL i = n; i < MAX; ++i) {
        if (is_Pal(i) && is_prime(i)) {
            answer = i;
            break;
        }  
    }

    return answer;
}

int main(void) {
    LL n;

    cin >> n;

    LL ret = solution(n);
    cout << ret;

    return 0;
}