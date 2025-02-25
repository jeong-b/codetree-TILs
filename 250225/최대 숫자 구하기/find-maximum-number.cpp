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

    for (int i = 1; i <= M; ++i) {
        numbers.insert(i);
    }

    for (int i = 0; i < N; ++i) {
        int input;
        cin >> input;
        numbers.erase(input);
        cout << *numbers.rbegin() << '\n';
    }

	return 0;
}