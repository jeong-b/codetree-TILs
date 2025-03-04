#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <cstring>

using namespace std;

const int MAX_N = 100;

int N, K;
bool map[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
vector<pair<int, int>> startPoints;
unordered_set<int> avalablePoints;

void Input() {
    cin >> N >> K;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < K; ++i) {
        int row, col;
        cin >> row >> col;
        startPoints.push_back({row - 1, col - 1});
    }
}

bool InRange(int row, int col) {
    return row >= 0 && row < N && col >= 0 && col < N;
}

bool CanGo(int row, int col) {
    if (!InRange(row, col)) return false;

    if (visited[row][col] || map[row][col]) return false;

    return true;
}

void BFS(int startRow, int startCol) {
    queue<pair<int, int>> q;
    q.push({startRow, startCol});
    avalablePoints.insert(startRow * 1000 + startCol);

    int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!q.empty()) {
        int nowRow = q.front().first;
        int nowCol = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nextRow = nowRow + dir[i][0];
            int nextCol = nowCol + dir[i][1];

            if(!CanGo(nextRow, nextCol)) continue;

            visited[nextRow][nextCol] = true;
            q.push({nextRow, nextCol});
            avalablePoints.insert(nextRow * 1000 + nextCol);
        }
    }

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    Input();

    for (auto it = startPoints.begin(); it != startPoints.end(); ++it) {
        BFS((*it).first, (*it).second);
    }

    cout << avalablePoints.size();

	return 0;
}