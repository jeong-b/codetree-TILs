#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int N;
    long long answer = 0;
    unordered_map<int, long long> ponits;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        int x;
        long long y;
        cin >> x >> y;

        if (ponits.find(x) != ponits.end()) {
            ponits[x] = min(ponits[x], y);
            continue;
        }
        ponits[x] = y;
    }

    for (auto it = ponits.begin(); it != ponits.end(); ++it) {
        answer += (*it).second;
    }

    cout << answer;

	return 0;
}