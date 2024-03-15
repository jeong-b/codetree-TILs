#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    set<int> s;
    
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        s.insert(input);
    }

    for (int i = 0; i < m; i++) {
        int input;
        cin >> input;
        if (s.find(input) != s.end()) {
            cout << input << endl;
        } 
        else if(s.upper_bound(input) == s.end()) {
            cout << -1 << endl;
        }
        else {
            cout << *s.upper_bound(input) << endl;
        }
    }

    return 0;
}