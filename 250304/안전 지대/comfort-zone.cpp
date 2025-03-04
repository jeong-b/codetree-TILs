#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, maxHeight = 0, safezone = 0;
int waterLevel = 1;

vector<vector<int>> houses;
vector<vector<bool>> visited;

bool InRange(int row, int col) {
    return row >= 0 && row < N && col >= 0 && col < M;
}

bool Cango(int row, int col, int level) {
    if(!InRange(row, col)) return false;

    if(visited[row][col] || houses[row][col] <= level) return false;

    return true;
}


void DFS(int row, int col, int level) {
    int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (int i = 0; i < 4; ++i) {
        int nextRow = row + dir[i][0];
        int nextCol = col + dir[i][1];

        if (!Cango(nextRow, nextCol, level)) continue;

        visited[nextRow][nextCol] = true;
        DFS(nextRow, nextCol, level);
    }
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> N >> M;

    houses.resize(N, vector<int>(M, 0));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> houses[i][j];
            maxHeight = max(maxHeight, houses[i][j]);
        }
    }

    for (int k = 1; k <= maxHeight; ++k) {
        int cnt = 0;
        //visited.assign(N, vector<bool>(M, false));
        visited.resize(N, vector<bool>(M));
for (int i = 0; i < N; i++) {
    fill(visited[i].begin(), visited[i].end(), false);
}


        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (visited[i][j] || houses[i][j] <= k) continue;
                DFS(i, j, k);
                ++cnt;
            }
        }

        if (cnt > safezone) {
            waterLevel = k;
            safezone = cnt;
        }
    }

    cout << waterLevel << ' ' << safezone;

	return 0;
}