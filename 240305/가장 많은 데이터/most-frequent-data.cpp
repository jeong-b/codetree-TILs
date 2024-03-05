#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<string, int> um;
    int answer = 1;
    for(int i = 0; i < n; i++) {
        string color;
        cin >> color;

        if(um.find(color) != um.end()) {
            answer = max(answer, ++um[color]);
        }
        else {
            um[color] = 1;
        }
    }
    
    cout << answer;

    return 0;
}