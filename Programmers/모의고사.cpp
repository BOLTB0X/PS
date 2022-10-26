// level 1
#include <string>
#include <vector>

using namespace std;

int student1[5] = {1, 2, 3, 4, 5};
int student2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
int student3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int score[3] = {0, };
    int max_score = -1;
    
    for (int i = 0; i < answers.size(); ++i) {
        if (answers[i] == student1[i % 5])
            score[0]++;
        
        if (answers[i] == student2[i % 8])
            score[1]++;
        
        if (answers[i] == student3[i % 10])
            score[2]++;
    }
    
    for (int i = 0; i < 3; ++i) {
        if (max_score < score[i])
            max_score = score[i];
    }
    
    // 최고점 찾기
    for (int i = 0; i < 3; ++i) {
        if (max_score == score[i])
            answer.push_back(i + 1);
    }
    
    return answer;
}