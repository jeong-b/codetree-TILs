#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

#define MAX_SIZE 500

using namespace std;

struct Node {
    int r, c, v;
};

struct cmp {
    bool operator() (Node left, Node right) {
        if (left.v != right.v) return left.v < right.v;
        else if (left.r != right.r) return left.r > right.r;
        else if (left.c != right.c) return left.c > right.c;
        return true;
    }
};

int arr[MAX_SIZE][MAX_SIZE];
int dp[MAX_SIZE][MAX_SIZE];
int temp[MAX_SIZE][MAX_SIZE];
int N, answer;
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

priority_queue<Node, vector<Node>, cmp> pq;

bool inRange(int y, int x) {
    return y >= 0 && y < N && x >= 0 && x < N;
}

 void canGo(int y, int x) {
     for (int i = 0; i < 4; i++) {
         int nextY = y + dir[i][0];
         int nextX = x + dir[i][1];

         if (!inRange(nextY, nextX)) continue;
         if (arr[y][x] >= arr[nextY][nextX]) continue;

         dp[y][x] = max(dp[nextY][nextX] + 1, dp[y][x]);
     }
 }

int main() {
    // input
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            pq.push({ i, j, arr[i][j] });
        }
    }

    // solve
    fill(&dp[0][0], &dp[MAX_SIZE - 1][MAX_SIZE], 1);
    while (!pq.empty()) {
        Node start = pq.top();
        pq.pop();
        canGo(start.r, start.c);
    }
    // ouput
     for (int i = 0; i < N; i++) {
         for (int j = 0; j < N; j++) {
             pq.push({ i, j, dp[i][j] });
         }
     }
     Node answer = pq.top();
     cout << answer.v;

    return 0;
}