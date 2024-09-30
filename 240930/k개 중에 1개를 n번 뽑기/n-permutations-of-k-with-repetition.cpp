#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> answer;

void Choose()
{
	if (answer.size() == K)
	{
		for (int i = 0; i < answer.size(); i++)
		{
			cout << answer[i] << ' ';
		}
		cout << endl;
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		answer.push_back(i);
		Choose();
		answer.pop_back();
	}
}

int main()
{
	cin >> N >> K;

	Choose();
	return 0;
}