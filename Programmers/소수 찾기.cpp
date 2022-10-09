// level 2 
#include <string>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

set<int> per;
int visited[10] = {0, };

int is_prime(int number) {
    if (number == 1 || number == 0)
        return 0;
        
    for (int i = 2; i<=(int)sqrt(number); ++i) {
        if (number % i == 0)
            return 0;
    }
    return 1;
}

void DFS(string numbers, string p, int level, int size) {
    if (level == size) {
        int prime = stoi(p);
        if (is_prime(prime))
            per.insert(prime);
        return;
    }
    
    for (int i = 0; i < numbers.length(); ++i) {
        if (visited[i])
            continue;
        visited[i] = 1;
        p.push_back(numbers[i]);
        DFS(numbers, p, level + 1, size);
        p.pop_back();
        visited[i] = 0;
    }
}

int solution(string numbers) {
    int answer = 0;
    int size = numbers.length();
    
    for (int i = 1; i <= size; ++i) {
        DFS(numbers, "", 0, i);
    }   

    answer = per.size();
    return answer;
}