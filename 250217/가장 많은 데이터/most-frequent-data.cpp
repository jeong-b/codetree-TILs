#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int N;
unordered_map<string, int> um;
int answer = 0;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;

        if (um.find(word) != um.end()) {
            um[word]++;
        }
        else {
            um.insert({word, 1});
        }

        answer = max(answer, um[word]);
    }

    cout << answer;

    return 0;
}