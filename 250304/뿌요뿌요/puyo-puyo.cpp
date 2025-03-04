#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> map;
vector<vector<bool>> visited;
unordered_map<int, int> m;

void Input() {
    cin >> N;
    map.resize(N, vector<int>(N));
    visited.resize(N, vector<bool>(N, false));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> map[i][j];
        }
    }
}

bool InRange(int row, int col) {
    return row >= 0 && row < N && col >= 0 && col < N;
}


bool IsSame(int row, int col, int info) {
    if (!InRange(row, col)) return false;

    if (visited[row][col] || map[row][col] != info) return false;

    return true;
}

int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void DFS(int row, int col, int info) {
    for (int i = 0; i < 4; ++i) {
        int nextRow = row + dir[i][0];
        int nextCol = col + dir[i][1];

        if(!IsSame(nextRow, nextCol, info)) continue;
        visited[nextRow][nextCol] = true;
        m[info]++;
        DFS(nextRow, nextCol, info); 

    }
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    Input();

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if(visited[i][j]) continue;
            //m.insert({map[i][j], 0});
            m[map[i][j]] = 0;            
            DFS(i, j, map[i][j]);
        }
    }

    int broken = 0, maxBlock = 0;

    for (auto it = m.begin(); it != m.end(); ++it) {
        if((*it).second >= 4) broken++;
        maxBlock = max(maxBlock, (*it).second);
    }

    cout << broken << ' ' << maxBlock;

	return 0;
}