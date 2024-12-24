#include <iostream>
#include <algorithm>
#define MAX_SIZE 20

using namespace std;

int N;
int map[MAX_SIZE][MAX_SIZE];

// 입력 함수
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

// 3x3 서브그리드 내 합의 최댓값 찾기
int findMaxSubgridSum()
{
    const int SUBGRID_SIZE = 3;
    int result = 0; // 최댓값 저장
    int temp = 0;   // 현재 서브그리드의 합

    // 격자 탐색
    for (int i = 0; i <= N - SUBGRID_SIZE; i++)
    {
        for (int j = 0; j <= N - SUBGRID_SIZE; j++)
        {
            // 3x3 서브그리드 합 계산
            temp = map[i][j] + map[i][j + 1] + map[i][j + 2]
                + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2]
                + map[i + 2][j] + map[i + 2][j + 1] + map[i + 2][j + 2];

            result = max(result, temp);
        }
    }
    return result;
}

int main()
{
    input();
    int answer = findMaxSubgridSum();
    cout << answer;
    return 0;
}