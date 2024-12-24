#include <iostream>
#include <algorithm>
#define MAX_SIZE 20

using namespace std;

int N;
int map[MAX_SIZE][MAX_SIZE];

// 변수 N을 입력받는 함수
void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}
}

// 격자내 완전탐색을 통한 최댓값 찾기
int find()
{
	int result = 0; // 계산의 결과 값
	int temp = 0; // 비교를 위한 변수
	// 완전탐색하며 최댓값 찾기
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = 0; j < N - 2; j++)
		{
			temp = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 1] + map[i + 1][j + 2] + map[i + 2][j + 1] + map[i + 2][j + 2];
			result = max(result, temp);
		}
	}
	return result;
}

int main()
{
	input();
	int answer = find(); // 격자내 최댓값을 나타내는 변수
	cout << answer;
	return 0;
}