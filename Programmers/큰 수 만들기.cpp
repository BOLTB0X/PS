// level 2
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int size = number.length();
    int max_idx = 0;
    
    for (int i = 1; i <= size - k; ++i) {
        int max_num = -1;
        for (int j = max_idx; j < k + i; ++j) {
            if (max_num < number[j] - '0') {
                max_num = number[j] - '0';
                max_idx = j;
            }        
        }
        answer += (max_num + '0');
        max_idx++;
    }
    return answer;
}