// 문제 정보(문제 링크) - 행복한 수열의 개수(https://www.codetree.ai/missions/2/problems/number-of-happy-sequence/description)
// 풀이 일시(풀이 시간) - 24. 08. 27

/* 구현 시나리오 */
/*
* 입력 받는 변수 : 격자의 크기 int n, 연속해야하는 숫자의 수 int m, 격자 정보 int map[n][n]
* 출력 하는 변수 : 행복한 수열의 수 int answer
* 풀이 필요 변수 : 연속으로 존재하는 숫자의 수 int cnt, 비교의 숫자 int pre

각 행, 열에서 연속된 숫자의 개수를 탐지하고 개수가 일정이상이면 answwer을 증가시킨다
*/

#include <iostream>

#define MAX_SIZE 100

using namespace std;

int n, m, arr[MAX_SIZE][MAX_SIZE];
int answer;
int cnt, pre;

int main()
{
	// input
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	// solve
	if (m == 1)
	{
		cout << 2 * n;
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		pre = arr[i][0];
		cnt = 1;
		for (int j = 1; j < n; j++)
		{
			if (arr[i][j] != pre)
			{
				pre = arr[i][j];
				cnt = 1;
				continue;
			}
			cnt++;
			if (cnt == m)
			{
				answer++;
				break;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		pre = arr[0][i];
		cnt = 1;
		for (int j = 1; j < n; j++)
		{
			if (arr[j][i] != pre)
			{
				pre = arr[j][i];
				cnt = 1;
				continue;
			}
			cnt++;
			if (cnt == m)
			{
				answer++;
				break;
			}
		}
	}

	// output
	cout << answer;

	return 0;
}