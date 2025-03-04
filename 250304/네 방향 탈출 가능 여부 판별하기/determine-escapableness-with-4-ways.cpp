#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 100;
const int MAX_M = 100;

int N, M;
bool map[MAX_N][MAX_M];
bool visited[MAX_N][MAX_M];

void Input() {
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> map[i][j];
        }
    }
}

bool InRage(int row, int col) {
    return row >= 0 && row < N && col >= 0 && col < M;
}

bool CanGo(int row, int col) {
    if (!InRage(row, col)) return false;

    if (visited[row][col] || !map[row][col]) return false;

    return true;
}

void BFS(int row, int col) {
    queue<pair<int, int>> q;
    q.push({row, col});

    int dir[4][2] = { {-1 , 0}, {1, 0}, {0, -1}, {0, 1}};
    
    while (!q.empty()) {
        int nowRow = q.front().first;
        int nowCol = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nextRow = nowRow + dir[i][0];
            int nextCol = nowCol + dir[i][1];

            if (!CanGo(nextRow, nextCol)) continue;
            visited[nextRow][nextCol] = true;
            q.push({nextRow, nextCol});
        }


    }
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    Input();

    BFS(0, 0);

    cout << visited[N - 1][M - 1];

	return 0;
}