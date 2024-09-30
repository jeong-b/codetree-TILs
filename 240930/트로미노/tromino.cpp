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
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			priority_queue<int> around_num;
			if (i - 1 >= 0) around_num.push(map[i - 1][j]);
			if (i + 1 < n) around_num.push(map[i + 1][j]);
			if (j - 1 >= 0) around_num.push(map[i][j - 1]);
			if (j + 1 < m) around_num.push(map[i][j + 1]);

			int first = around_num.top();
			around_num.pop();
			int second = around_num.top();
			
			temp = map[i][j] + first + second;
			answer = max(answer, temp);
		}
	}

	// output
	cout << answer;

	return 0;
}