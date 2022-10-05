// level 2
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
   
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    
    for (int number : numbers) {
        v.push_back(to_string(number));
    }
    
    sort(v.begin(), v.end(), compare);
    
    for (string vv: v) {
        answer += vv;
    }
    if (answer[0] == '0')
        answer = "0";
    return answer;
}