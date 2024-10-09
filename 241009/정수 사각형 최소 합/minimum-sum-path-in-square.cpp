#include <iostream>
#include <algorithm>

#define MAX_SIZE 100

using namespace std;

int arr[MAX_SIZE][MAX_SIZE];
int dp[MAX_SIZE][MAX_SIZE];
int N;

int main() {
    // input
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    // solve
    dp[0][N - 1] = arr[0][N - 1];
    for (int i = N - 2; i >= 0; i--) {
        dp[0][i] = dp[0][i + 1] + arr[0][i];
    }
    for (int i = 1; i < N; i++) {
        dp[i][N - 1] = dp[i - 1][N - 1] + arr[i][N - 1];
    }

    for (int i = 1; i < N; i++) {
        for (int j = N - 2; j >= 0; j--) {
            dp[i][j] = min(dp[i - 1][j] + arr[i][j], dp[i][j + 1] + arr[i][j]);
        }
    }

    // output
    cout << dp[N - 1][0];
    
    return 0;
}