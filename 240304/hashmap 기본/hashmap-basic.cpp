#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<int, int> um;
    for(int i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;

        if(cmd == "add") {
            int key, value;
            cin >> key >> value;
            if(um.find(key) == um.end()) {
                um.insert({key, value});
            }
            else {
                um.erase(key);
                um.insert({key, value});
            }
        }
        else if(cmd == "remove") {
            int key;
            cin >> key;
            um.erase(key);
        }
        else if(cmd == "find") {
            int key;
            cin >> key;
            if(um.find(key) == um.end()) {
                cout << "None" << endl;
            }
            else {
                cout << um.find(key)->second << endl;
            }
        }
    }

    return 0;
}