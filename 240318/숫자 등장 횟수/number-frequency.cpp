#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	/* 변수 선언 */
	int n, m; //  원소의 개수  int n, 질의의 개수 int m;
	unordered_map<int, int> um; // 값을 저장하는 unordered_map<int, int> um
	int input; // 입력으로 주어지는 값  int input

	/* 변수 입력 */
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> input;

		if (um.find(input) == um.end()) um.insert({ input, 1 });
		else um[input]++;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> input;
		if (um.find(input) == um.end()) cout << 0 << ' ';
		else cout << um[input] << ' ';
	}

	return 0;
}