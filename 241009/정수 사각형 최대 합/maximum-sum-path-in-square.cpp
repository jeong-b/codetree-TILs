#include <iostream>
#include <algorithm>

#define MAX_SIZE 100

using namespace std;

int arr[MAX_SIZE][MAX_SIZE];
int sum[MAX_SIZE][MAX_SIZE];
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
    // init
    sum[0][0] = arr[0][0];
    for (int i = 1; i < N; i++) {
        sum[i][0] = sum[i - 1][0] + arr[i][0];
        sum[0][i] = sum[0][i - 1] + arr[0][i];
    }

    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            sum[i][j] = max(sum[i - 1][j] + arr[i][j], sum[i][j - 1] + arr[i][j]);
        }
    }

    // output
    cout << sum[N - 1][N - 1];

    return 0;
}