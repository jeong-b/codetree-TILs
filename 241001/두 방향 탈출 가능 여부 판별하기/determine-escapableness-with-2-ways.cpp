#include <iostream>

#define MAX_SIZE 100

using namespace std;

bool map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int dir[2][2] = { {1,0}, {0,1} };
int n, m;
bool answer;

void DFS(int nowY, int nowX)
{
	for (int i = 0; i < 2; i++)
	{
		int nextY = nowY + dir[i][0];
		int nextX = nowX + dir[i][1];

		if (nextY >= n || nextX >= m) continue;
		if (!map[nextY][nextX] || visited[nextY][nextX]) continue;

		visited[nextY][nextX] = true;
		DFS(nextY, nextX);
	}
}

int main()
{
	// input
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	// solve
	visited[0][0] = true;
	DFS(0, 0);

	cout << visited[n - 1][m - 1];

	return 0;
}