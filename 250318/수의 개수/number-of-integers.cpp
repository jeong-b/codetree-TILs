#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> arr, targets;

void input() {
    cin >> N >> M;

    arr.resize(N);
    targets.resize(M);

    for (int i = 0; i < N; ++i) cin >> arr[i];
    for (int i = 0; i < M; ++i) cin >> targets[i];
}

int lower_bound(int target) {
    int left = 0, right = N - 1;
    int idx = N;

    while (left <= right) {
        int mid = (left + right) / 2;
        
        if (arr[mid] >= target) {
            right = mid - 1;
            idx = min(idx, mid);
        }
        else left = mid + 1;
    }

    return idx;
}

int upper_bound(int target) {
    int left = 0, right = N - 1;
    int idx = N;

    while (left <= right) {
        int mid = (left + right) / 2;
        
        if (arr[mid] > target) {
            right = mid - 1;
            idx = min(idx, mid);
        }
        else left = mid + 1;
    }

    return idx;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    input();

    for (int target : targets) cout << upper_bound(target) - lower_bound(target) << '\n';

	return 0;
}