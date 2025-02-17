#include <iostream>
#include <unordered_map>

using namespace std;

int N, M;
unordered_map<int, int> um;

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int number;
        cin >> number;

        if (um.find(number) != um.end()) {
            um[number]++;            
        }
        else {
            um.insert({number, 1});
        }
    }

    for (int i = 0; i < M; i++) {
        int number;
        cin >> number;

        if (um.find(number) != um.end()) {
            cout << um[number] << ' ';
        }
        else {
            cout << 0 << ' ';
        }
    }

    return 0;
}