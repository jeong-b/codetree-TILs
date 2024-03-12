#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_set<int> us;
    for (int i = 0; i < n; i++) {
        string cmd;
        int input;
        cin >> cmd >> input;

        if (cmd == "add") us.insert(input);
        else if (cmd == "remove") us.erase(input);
        else if (cmd == "find") {
            if(us.find(input) != us.end()) cout << "true" << endl;
            else cout << "false" <<endl;
        }
    }
    
    return 0;
}