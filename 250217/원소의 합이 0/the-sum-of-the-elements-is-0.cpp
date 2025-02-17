#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int N;
vector<vector<int>> v;
unordered_map<int, int> um1, um2;
int answer = 0;

int main() {
    cin >> N;

    v.resize(4);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < N; ++j) {
            v[i].resize(N);
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            um1[v[0][i]+v[1][j]]++;
            um2[v[2][i]+v[3][j]]++;
        }
    }

    for (auto it =um1.begin(); it != um1.end(); ++it) {
        int temp = -((*it).first);
        if (um2.find(temp) != um2.end()) {
            answer += (*it).second * um2[temp];
        }
    }

    cout << answer;

    return 0;
}