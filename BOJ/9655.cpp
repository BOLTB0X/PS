// 9655 돌 게임
#include <iostream>

using namespace std;

int main(void) 
{
    int n;

    cin >> n;
    string answer = n % 2 ? "SK" : "CY";
    cout << answer;
    return 0;
}
