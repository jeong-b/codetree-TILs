#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> v(N + 1);
    vector<bool> visited(N + 1, false);

    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;

        v[x].push_back(y);
        v[y].push_back(x);
    }

    queue<int> q;
    int answer = 0;

    q.push(1);
    visited[1] = true;  // 큐에 넣을 때 방문 체크

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i = 0; i < v[now].size(); ++i) {
            int next = v[now][i];

            if (!visited[next]) {
                visited[next] = true;  // 큐에 넣을 때 방문 체크
                q.push(next);
                ++answer;
            }
        }
    }

    cout << answer;

    return 0;
}
