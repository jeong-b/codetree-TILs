#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, m;
    priority_queue<int> pq;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        pq.push(input);
    }

    for (int i = 0; i < m; i++)
    {
        int temp = pq.top() - 1;
        pq.pop();
        pq.push(temp);
    }

    cout << pq.top();

    return 0;
}