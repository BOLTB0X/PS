#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int size = number.length();
    int max_idx = 0; // 비교용
    
    // 변수 size 길이의 문자열안에 k만큼 써야함
    for (int i = 1; i <= size - k; ++i) {
        int max_number = -1; // 탐색 전 초기화
        // max_idx부터 K만큼 큰 수 탐색
        // 처음에는 0
        for (int j = max_idx ; j < k + i; ++j) {
            if (max_number < number[j] - '0') {
                max_number = number[j] - '0';
                max_idx = j; // 스티트 구분을 위해
            }
        }
        answer += (max_number + '0');
        max_idx++;
    }
    return answer;
}