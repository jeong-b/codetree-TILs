#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
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
            if (numbers.find(input) != numbers.end()) {
                cout << "true\n";
                continue;
            }
            cout << "false\n";

        }
        else if (cmd == "lower_bound") {
            cin >> input;
            if (numbers.lower_bound(input) == numbers.end()) {
                cout << "None\n";
                continue;
            }
            cout << *numbers.lower_bound(input) << '\n';
        }
        else if (cmd == "upper_bound") {
            cin >> input;
            if (numbers.upper_bound(input) == numbers.end()) {
                cout << "None\n";
                continue;
            }
            cout << *numbers.upper_bound(input) << '\n';

        }
        else if (cmd == "largest") {
            if (numbers.size() == 0) {
                cout << "None\n";
                continue;
            }
            cout << *numbers.rbegin() << '\n';
        }
        else if (cmd == "smallest") {
            if (numbers.size() == 0) {
                cout << "None\n";
                continue;
            }
            cout << *numbers.begin() << '\n';
        }
    }

	return 0;
}