#include <iostream>
#include <string>
#include <list>

using namespace std;

int main() {
    int N;
    cin >> N;

    list<int> answer;

    for(int i = 0; i < N; i++) {
        string cmd;
        cin >> cmd;

        if(cmd == "push_front") {
            int num;
            cin >> num;
            answer.push_front(num);
        }
        else if(cmd == "push_back") {
            int num;
            cin >> num;
            answer.push_back(num);
        }
        else if(cmd == "pop_front") {
            cout << answer.front() << endl;
            answer.pop_front();
        }
        else if(cmd == "pop_back") {
            cout << answer.back() << endl;
            answer.pop_back();
        }
        else if(cmd == "size") {
            cout << answer.size() << endl;
        }
        else if(cmd == "empty") {
            cout << answer.empty() << endl;
        }
        else if(cmd == "front") {
            cout << answer.front() << endl;
        }
        else if(cmd == "back") {
            cout << answer.back() << endl;
        }
    }

    return 0;
}