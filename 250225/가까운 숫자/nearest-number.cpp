#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int N, answer = 1e9;
    cin >> N;

    set<int> numbers;
    numbers.insert(0);

    for (int i = 0; i < N; ++i) {
        int input;
        int small = 1e9, big = 1e9;
        cin >> input;

        auto it = numbers.upper_bound(input);
        if (it != numbers.end()) {
            small = *it - input;
        }

        if (it != numbers.begin()) {
            --it;
            big = input - *it;
        }

        answer = min(answer, min(small, big));
        numbers.insert(input);

        cout << answer << '\n';
    }

	return 0;
}