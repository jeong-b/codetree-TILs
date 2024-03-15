#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
    int N, input;
    string cmd;
    priority_queue<int> pq;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> cmd;

        if (cmd == "push")
        {
            cin >> input;
            pq.push(input);
        }
        else if (cmd == "pop")
        {
            cout << pq.top() << endl;
            pq.pop();
        }
        else if (cmd == "size")
        {
            cout << pq.size() << endl;
        }
        else if (cmd == "empty")
        {
            if (pq.empty()) cout << 1 << endl;
            else cout << 0 << endl;
        }
        else if (cmd == "top")
        {
            cout << pq.top() << endl;
        }
    }

    return 0;
}