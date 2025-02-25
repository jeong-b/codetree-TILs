#include <iostream>
#include <string>
#include <set>
#include <unordered_map>
#include <functional>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    set<int> numbers;

    unordered_map<string, function<void()>> commands;
    int input;  // 공통 입력 변수

    // 🔹 명령어와 동작을 매핑
    commands["add"] = [&]() { cin >> input; numbers.insert(input); };
    commands["remove"] = [&]() { cin >> input; numbers.erase(input); };
    commands["find"] = [&]() {
        cin >> input;
        cout << (numbers.find(input) != numbers.end() ? "true\n" : "false\n");
    };
    commands["lower_bound"] = [&]() {
        cin >> input;
        auto it = numbers.lower_bound(input);
        cout << (it == numbers.end() ? "None\n" : to_string(*it) + "\n");
    };
    commands["upper_bound"] = [&]() {
        cin >> input;
        auto it = numbers.upper_bound(input);
        cout << (it == numbers.end() ? "None\n" : to_string(*it) + "\n");
    };
    commands["largest"] = [&]() {
        cout << (numbers.empty() ? "None\n" : to_string(*numbers.rbegin()) + "\n");
    };
    commands["smallest"] = [&]() {
        cout << (numbers.empty() ? "None\n" : to_string(*numbers.begin()) + "\n");
    };

    // 🔹 명령어 실행 루프
    for (int i = 0; i < N; ++i) {
        string cmd;
        cin >> cmd;

        if (commands.find(cmd) != commands.end()) {
            commands[cmd]();  // 해당 명령어 실행
        }
    }

    return 0;
}
