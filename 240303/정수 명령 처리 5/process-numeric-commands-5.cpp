#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int N;
    cin >> N;

    vector<int> answer;

    for(int i = 0; i < N; i++) {
        string cmd;
        cin >> cmd;

        if(cmd == "push_back") {
            int num;
            cin >> num;
            answer.push_back(num);
        }
        else if(cmd == "pop_back") {
            answer.pop_back();
        }
        else if(cmd == "size") {
            cout << answer.size() << endl;
        }
        else if(cmd == "get") {
            int index;
            cin >> index;
            cout << answer[index - 1] << endl;
        }
    }    

    return 0;
}