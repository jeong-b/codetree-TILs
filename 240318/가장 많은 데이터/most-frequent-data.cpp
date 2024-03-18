#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
	/* 변수 선언 */
	int n; // 입	력할 문자열의 개수 int n
	string color; // 입력할 문자열 string color
	unordered_map<string, int> um; // 문자열을 저장하는 unordered_map<string, int> um
	int answer = 0; // 최대 횟수를 저장하는 int answer

	/* 변수 입력 */
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> color;

		if (um.find(color) == um.end()) um.insert({ color, 1 });
		else um[color]++;

		answer = max(answer, um[color]);
	}

	/* 정답 출력 */
	cout << answer;

	return 0;
}