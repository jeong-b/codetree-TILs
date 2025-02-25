#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    set<int> numbers;

    for (int i = 0; i < N; ++i) {
        int input;
        string cmd;
        cin >> cmd;

        if (cmd == "add") {
            cin >> input;
            numbers.insert(input);
        } 
        else if (cmd == "remove") {
            cin >> input;
            numbers.erase(input);
        } 
        else if (cmd == "find") {
            cin >> input;
            cout << (numbers.find(input) != numbers.end() ? "true\n" : "false\n");
        } 
        else if (cmd == "lower_bound") {
            cin >> input;
            cout << (numbers.lower_bound(input) == numbers.end() ? "None\n" : to_string(*numbers.lower_bound(input)) + "\n");
        } 
        else if (cmd == "upper_bound") {
            cin >> input;
            cout << (numbers.upper_bound(input) == numbers.end() ? "None\n" : to_string(*numbers.upper_bound(input)) + "\n");
        } 
        else if (cmd == "largest") {
            cout << (numbers.empty() ? "None\n" : to_string(*numbers.rbegin()) + "\n");
        } 
        else if (cmd == "smallest") {
            cout << (numbers.empty() ? "None\n" : to_string(*numbers.begin()) + "\n");
        }
    }

    return 0;
}
