#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> arr, targets;

void input() {
    cin >> N >> M;

    arr.resize(N);
    targets.resize(M);

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    for (int i = 0; i < M; ++i) {
        cin >> targets[i];
    }
}

int binary_search(int target) {
    int left = 0, right = N - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == target) {
            return mid + 1;
        }

        if (arr[mid] > target) right = mid - 1;
        else left = mid + 1;
    }

    return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    input();

    for (int target : targets) {
        cout << binary_search(target) << '\n';
    }

	return 0;
}