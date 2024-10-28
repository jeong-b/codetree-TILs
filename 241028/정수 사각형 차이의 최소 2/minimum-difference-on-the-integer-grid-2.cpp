#include <iostream>
#include <algorithm>

#define MAX_SIZE 100

using namespace std;

struct Node
{
	int maximun, minimun, gap;
};

int n;
int map[MAX_SIZE][MAX_SIZE];
Node dp[MAX_SIZE][MAX_SIZE];

void initialize()
{
	dp[0][0].maximun = map[0][0];
	dp[0][0].minimun = map[0][0];
	dp[0][0].gap = 0;

	for (int i = 1; i < n; i++)
	{
		if (map[0][i] < dp[0][i - 1].minimun) dp[0][i].minimun = map[0][i];
		else dp[0][i].minimun = dp[0][i - 1].minimun;
		if (map[0][i] > dp[0][i - 1].maximun) dp[0][i].maximun = map[0][i];
		else dp[0][i].maximun = dp[0][i - 1].maximun;
		dp[0][i].gap = dp[0][i].maximun - dp[0][i].minimun;

		if (map[i][0] < dp[i - 1][0].minimun) dp[i][0].minimun = map[i][0];
		else dp[i][0].minimun = dp[i - 1][0].minimun;
		if (map[i][0] > dp[i - 1][0].maximun) dp[i][0].maximun = map[i][0];
		else dp[i][0].maximun = dp[i - 1][0].maximun;
		dp[i][0].gap = dp[i][0].maximun - dp[i][0].minimun;
	}
}

void compare()
{
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			Node up, left;

			up.maximun = max(map[i][j], dp[i - 1][j].maximun);
			up.minimun = min(map[i][j], dp[i - 1][j].minimun);
			up.gap = up.maximun - up.minimun;

			left.maximun = max(map[i][j], dp[i][j - 1].maximun);
			left.minimun = min(map[i][j], dp[i][j - 1].minimun);
			left.gap = left.maximun - left.minimun;

			if (up.gap < left.gap) dp[i][j] = up;
			else dp[i][j] = left;
		}
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
	initialize();

	compare();

	// output
	cout << dp[n - 1][n - 1].gap;

	return 0;
}