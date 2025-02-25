#include <iostream>
#include <set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    set<int> numbers;
    for (int i = 0; i < N; ++i) {
        int input;
        cin >> input;
        numbers.insert(input);
    }

    for (int i = 0; i < M; ++i) {
        int input;
        cin >> input;
        cout << (numbers.lower_bound(input) != numbers.end() ? *numbers.lower_bound(input) : -1) << '\n'; 
    }

	return 0;
}