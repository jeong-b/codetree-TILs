// 문제 정보(문제 링크) - 최고의 33위치(https://www.codetree.ai/missions/2/problems/best-place-of-33/introduction)
// 풀이 일시(풀이 시간) - 24. 08. 27

/* 구현 시나리오 */
/*
* 입력 받는 변수 : 격자의 크기 int N, 격자 정보 bool map[N][N]
* 출력 하는 변수 : 3*3 격자내 최대 동전수 int answer
* 풀이 필요 변수 : 이전 위치의 값 int prev, 현재위치의 값 int now

좌측 상단 부터 개수를 확인하고 해당 개수를 이전의 개수와 비교하여 최댓값만 저장한다.
*/

#include <iostream>
#include <algorithm>

#define MAX_SIZE 20

using namespace std;

int N;
bool arr[MAX_SIZE][MAX_SIZE];
int answer;
int now;

int main()
{
	// input
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			bool input;
			cin >> input;
			arr[i][j] = input;
		}
	}

	// solve
	answer = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (!arr[i][j]) continue;
			answer++;
		}
	}
	now = 0;
	for (int i = 0; i <= N - 3; i++)
	{
		for (int j = 0; j <= N - 3; j++)
		{
			if (i + j == 0) continue;
			for (int p = i; p < i + 3; p++)
			{
				for (int q = j; q < j + 3; q++)
				{
					if (!arr[p][q]) continue;
					now++;
				}
			}
			answer = max(answer, now);

			now = 0;
		}
	}

	// output
	cout << answer;

	return 0;
}