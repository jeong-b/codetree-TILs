#include <iostream>
#include <algorithm>
#include <queue>

#define MAX_SIZE 200

using namespace std;

int n, m, answer;
int map[MAX_SIZE][MAX_SIZE];

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
	int temp = 0;
	answer = 0;
	priority_queue<int> around_num;
	for (int i = 1; i < n - 1; i++)
	{
		for (int j = 1; j < m - 1; j++)
		{
			around_num.push(map[i - 1][j]);
			around_num.push(map[i + 1][j]);
			around_num.push(map[i][j - 1]);
			around_num.push(map[i][j + 1]);

			int first = around_num.top();
			around_num.pop();
			int second = around_num.top();
			around_num.pop();
			around_num.pop();
			around_num.pop();

			temp = map[i][j] + first + second;
			answer = max(answer, temp);
		}
	}

	// output
	cout << answer;

	return 0;
}