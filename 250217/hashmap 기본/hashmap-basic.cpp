#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int N;
unordered_map<int, int> um;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        int key, value;
        string command;
        cin >> command;

        if (command == "add") {
            cin >> key >> value;
            um[key] = value;
            // um.insert({key, value}); // 기존 키 존재시 덮어쓰기를 수행하지 않음.
        }
        else if (command == "remove") {
            cin >> key;
            um.erase(key);
        }
        else if (command == "find") {
            cin >> key;
            if (um.find(key) != um.end()) {
                cout << (*um.find(key)).second << endl;
            }
            else {
                cout << "None" << endl;
            }
        }
    }

    return 0;
}