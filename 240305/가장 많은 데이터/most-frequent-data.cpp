#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<string, int> um;
    vector<string> v;
    for(int i = 0; i < n; i++) {
        string color;
        cin >> color;

        if(um.find(color) != um.end()) {
            um[color]++;
        }
        else {
            um[color] = 1;
            v.push_back(color);
        }
    }

    int answer = 0, len = v.size();
    for(int i = 0; i < len; i++) {
        if(answer < um[v[i]]) {
            answer = um[v[i]];
        }
    }

    cout << answer;
    
    return 0;
}