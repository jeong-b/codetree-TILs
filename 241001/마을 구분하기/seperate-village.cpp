#include <iostream>
#include <vector>
#include <queue>

#define MAX_SIZE 25

using namespace std;

int n;
bool map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int dir[4][2] = { {-1,0}, { 0,1 }, {1,0}, {0,-1} };
vector<int> town;
priority_queue<int, vector<int>, greater<int>> answer;

bool InRange(int y, int x)
{
	return x >= 0 && x < n && y >= 0 && y < n;
}

bool CanGo(int y, int x)
{
	if (!InRange) return false;
	if (!map[y][x] || visited[y][x]) return false;
	return true;
}

void FindTown(int y, int x, int townNum)
{
	for (int i = 0; i < 4; i++)
	{
		int nextY = y + dir[i][0];
		int nextX = x + dir[i][1];

		if (!CanGo(nextY, nextX)) continue;
		visited[nextY][nextX] = true;
		town[townNum]++;
		FindTown(nextY, nextX, townNum);
	}	
}


int main()
{
	// input
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	
	// solve
	int townNum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!CanGo(i, j)) continue;

			visited[i][j] = true;
			town.push_back(1);
			FindTown(i, j, townNum);
			townNum++;
		}
	}
	for (int i = 0; i < town.size(); i++)
	{
		answer.push(town[i]);
	}

	// output
	cout << answer.size() << endl;
	while (!answer.empty())
	{
		cout << answer.top() << endl;
		answer.pop();
	}

	return 0;
}