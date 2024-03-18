#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	/* 변수 선언 */
	int n; // 입	력할 문자열의 개수 int n
	string color; // 입력할 문자열 string color
	map<string, int> m; // 문자열을 저장하는 map<string, int> m

	/* 변수 입력 */
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> color;
		if (m.find(color) == m.end()) m.insert({ color, 1 });
		else m[color]++;
	}
	cout << m.begin()->second;

	return 0;
}