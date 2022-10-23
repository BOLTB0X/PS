// 1927 최소 힙
 #include <iostream>
 #include <queue>
 #include <vector>
 #include <functional>

 using namespace std;

 void solution(int n) {
    priority_queue<int, vector<int>, greater<int>> pq;
    int data;

    for (int i = 0; i < n; ++i) {
        cin >> data;

        if (data == 0) {
            if (pq.empty())
                cout << 0 << "\n";

            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else {
            pq.push(data);
        }
    }
    return;
 }

 int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;

    cin >> n;
    solution(n);
    return 0;
 }