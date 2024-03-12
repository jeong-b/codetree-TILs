#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n, m;
    cin >> n;

    unordered_set<int> us;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;

        us.insert(input);
    }

    cin >> m;

    vector<int> v;
    for (int i = 0; i < m; i++) {
        int input;
        cin >> input;

        v.push_back(input);
    }

    for (int i = 0; i < m; i++) {
        if(us.find(v[i]) != us.end()) cout << "1 ";
        else cout << "0 ";
    }
   
    return 0;
}