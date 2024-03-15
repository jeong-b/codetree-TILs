#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int main() {
    int n, input;
    priority_queue<int, vector<int>, greater<int>> pq;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        if (input == 0)
        {
            if (pq.empty()) cout << 0 << endl;
            else
            {
                cout << pq.top() << endl;
                pq.pop();
            }
        }
        else
        {
            pq.push(input);
        }
    }
    return 0;
}