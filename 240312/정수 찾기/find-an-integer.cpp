#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int n, m;
    unordered_set<int> us;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        us.insert(input);
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        int input;
        cin >> input;
        if(us.find(input) != us.end()) cout << 1 << endl;
        else cout << 0 << endl;
    }
    
    return 0;
}