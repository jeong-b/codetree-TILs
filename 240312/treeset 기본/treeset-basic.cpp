#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    set<int> s;

    for (int i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;

        if (cmd == "add") {
            int input;
            cin >> input;
            s.insert(input);
        }
        else if (cmd == "remove") {
            int input;
            cin >> input;
            s.erase(input);
        }
        else if (cmd == "find") {
            int input;
            cin >> input;
            if (s.find(input) != s.end()) cout << "true" << endl;
            else cout << "false" << endl;
        }
        else if (cmd == "lower_bound") {
            int input;
            cin >> input;
            if (s.lower_bound(input) != s.end()) cout << *s.lower_bound(input) << endl;
            else cout << "None" << endl;
        }
        else if (cmd == "upper_bound") {
            int input;
            cin >> input;
            if (s.upper_bound(input) != s.end()) cout << *s.upper_bound(input) << endl;
            else cout << "None" << endl;
        }
        else if (cmd == "largest") {
            if(s.rbegin() != s.rend()) cout << *s.rbegin() << endl;
            else cout << "None" << endl;
        }
        else if (cmd == "smallest") {
            if(s.rbegin() != s.rend()) cout << *s.begin() << endl;
            else cout << "None" << endl;
        }
    }


    return 0;
}