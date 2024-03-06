#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    int k;
    cin >> n >> k;

    vector<int> v;
    unordered_map<int, int> num;
    for(int i = 0; i < n; i++) {
        int input;
        cin >> input;

        v.push_back(input);
        
        if(num.find(input) != num.end()) num[input]++;        
        else num.insert({input, 1});
    }

    int answer = 0;
    for(int i = 0; i < n; i++) {
        int target = k - v[i];

        if(num.find(target) != num.end()) {
            answer += num[target];
        }
    }

    cout << answer / 2;

    return 0;
}