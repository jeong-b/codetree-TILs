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
    unordered_map<int, long long> minYByX;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        int x;
        long long y;
        cin >> x >> y;

        if (minYByX.find(x) != minYByX.end()) {
            minYByX[x] = min(minYByX[x], y);
        }
        else {
            minYByX[x] = y;
        }
    }

    for (const auto& pair : minYByX) {
        answer += pair.second;
    }

    cout << answer;

	return 0;
}