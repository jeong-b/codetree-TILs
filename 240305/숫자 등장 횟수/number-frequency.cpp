#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    unordered_map<int, int> um;
    for(int i =  0; i < n; i++) {
        int input;
        cin >> input;
        if(um.find(input) != um.end()) {
            um[input]++;
        }
        else {
            um.insert({input, 1});
        }
    }

    for(int i = 0; i < m; i++) {
        int input;
        cin >> input;
        if(um.find(input) != um.end()) {
            cout << um[input] << ' ';
        }
        else {
            cout << "0 "; 
        }
    }

    return 0;
}