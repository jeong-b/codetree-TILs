#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_set<int> us;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;

        us.insert(input);
    }

    cout << us.size();
    
    return 0;
}