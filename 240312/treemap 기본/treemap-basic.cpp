#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, int> m;
    for (int i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;

        if (cmd == "add") {
            int key, value;
            cin >> key >> value;
            // m.insert({ key, value });
            m[key] = value;
        }
        else if (cmd == "remove") {
            int key;
            cin >> key;
            m.erase(key);
        }
        else if (cmd == "find") {
            int key;
            cin >> key;
            if (m.find(key) != m.end()) cout << m[key] << endl;
            else cout << "None" << endl; 
        }
        else if (cmd == "print_list") {
            if(m.empty()) cout << "None" << endl;
            else {
                map<int, int>::iterator it;
                for (it = m.begin(); it != m.end(); it++) {
                    cout << (it -> second) << " ";
                }
                cout << endl;
            }
        }
    }
    
    return 0;
}