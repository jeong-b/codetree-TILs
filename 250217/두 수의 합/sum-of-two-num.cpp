#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int N, K;
unordered_map<long long, int> um;
unordered_set<long long> us;

int main() {
    int answer = 0;
    cin >> N >> K;
    
    for (int i = 0; i < N; i++) {
        long long number;
        cin >> number;

        if (um.find(number) != um.end()) {
            um[number]++;
        }
        else {
            um.insert({number, 1});
        }
    }

    for (auto it = um.begin(); it != um.end(); ++it) {
        long long key = (*it).first;
        long long temp = K - key;

        if (um.find(temp) == um.end()) continue;
        if (us.find(key) != us.end()) continue;

        if (key == temp) {
            answer += (((*it).second) * ((*it).second - 1) / 2);
            continue;
        }

        answer += ((*it).second) * ((*um.find(temp)).second);
        us.insert(temp);
    }

    cout << answer;

    return 0;
}