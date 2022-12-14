// level 1
#include <string>
#include <vector>

using namespace std;

vector<int> students;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    students.resize(n + 1, 1);
    
    for (int l: lost)
        students[l]--;
    
    for (int r: reserve) 
        students[r]++;

    for (int i = 1; i <= n; ++i) {
        if (students[i] == 0) {
            // 맨 앞
            if (i == 1 && students[i + 1] == 2) {
                students[i]++;
                students[i + 1]--;
            }
            
            // 맨 뒤
            else if (i == n && students[i - 1] == 2) {
                students[i]++;
                students[i - 1]--;
            }
            
            // 나머지
            else {
                // 먼저 앞에 확인
                if (students[i - 1] == 2) {
                    students[i]++;
                    students[i - 1]--;
                }
                
                // 뒤를 확인
                else if (students[i + 1] == 2) {
                    students[i]++;
                    students[i + 1]--;
                }
            }
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        if (students[i] != 0)
            answer++;
    }
    
    return answer;
}