#include <iostream>
#include <set>

using namespace std;

int main() {
    int T;
    cin >> T;


    for(int i = 0; i < T; i++) {
        int k;
        set<int> s;
        cin >> k;

        for (int j = 0; j < k; j++) {
            char cmd;
            int n;
            cin >> cmd >> n;

            if (cmd == 'I') s.insert(n);
            else if (cmd == 'D') {
                if (s.rbegin() == s.rend()) continue;

                if (n == 1) s.erase(*s.rbegin());
                else if (n == -1) s.erase(*s.begin());
            }
        }
        
        if (s.rbegin() == s.rend()) cout << "EMPTY\n";
        else cout << *s.rbegin() << " " << *s.begin() << endl;
    }
    return 0;
}