#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int N, K;
unordered_map<int, int> um;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> N >> K;

    for (int i = 0; i < N; ++i) {
        int number;
        cin >> number;
        um[number]++;
    }

    auto cmp = [](const pair<int, int>& left, const pair<int, int>& right) {
        if (left.second == right.second) return left.first < right.first;
        return left.second < right.second;
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

    for (const auto &item : um) {
        pq.push(item);
    }

    for (int i = 0; i < K; i++) {
        cout << pq.top().first << ' ';
        pq.pop();
    }

    return 0;
}