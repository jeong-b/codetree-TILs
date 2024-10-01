#include <iostream>
#include <vector>

#define MAX_SIZE 1000

using namespace std;

vector<int> graph[MAX_SIZE + 1];
bool visited[MAX_SIZE + 1];
int answer = 0;

void DFS(int vertex)
{
	for (int i = 0; i < graph[vertex].size(); i++)
	{
		int current = graph[vertex][i];
		if (!visited[current])
		{
			visited[current] = true;
			answer++;
			DFS(current);
		}
	}
}
	
int main()
{
	// input
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int to, from;
		cin >> to >> from;
		graph[to].push_back(from);
		graph[from].push_back(to);
	}

	// solve
	visited[1] = true;
	DFS(1);

	return 0;
}