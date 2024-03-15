#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

int main() {
    int n, m;
    set<pair <int, int>> s;
    vector<pair<int, int>> v;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        s.insert(make_pair(x, y));
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }

    for (int i = 0; i < m; i++) {
        if (s.lower_bound(v[i]) == s.end()) {
            cout << -1 << " " << -1 << endl;
        }
        else {
            cout << (*s.lower_bound(v[i])).first << " " << (*s.lower_bound(v[i])).second << endl;
        }
        
    }
    return 0;
}