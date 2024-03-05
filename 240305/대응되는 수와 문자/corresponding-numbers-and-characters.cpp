#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    unordered_map<string, string> um1;
    unordered_map<string, string> um2;
    for(int i = 0; i < n; i++) {
        string input;
        cin >> input;
        um1.insert({input, to_string(i + 1)});
        um2.insert({to_string(i + 1), input});
    }

    for(int i = 0; i < m; i++) {
        string cmd;
        cin >> cmd;
        if(um1.find(cmd) != um1.end()) {
            cout << um1[cmd] << endl;
        }
        else {
            cout << um2[cmd] << endl;
        }
    }
    return 0;
}