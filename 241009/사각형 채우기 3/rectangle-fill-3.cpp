#include <iostream>
#include <cstring>

#define MAX_SIZE 1000

using namespace std;

long long dp[MAX_SIZE];
int N;

long long count(int col) {
    if (dp[col] != -1) {
        return dp[col];
    }

    if (col == 0) dp[col] = 1;
    else if (col == 1) dp[col] = 2;
    else if (col == 2) dp[col] = 7;
    else {
        dp[col] = ((count(col - 1) * 2) + (count(col - 2) * 3)) % 1000000007;
        for (int i = col - 3; i >= 0; i--) {
            dp[col] = (dp[col] + (count(i) * 2)) % 1000000007;
        }
    }

    return dp[col];
}

int main() {
    // input
    cin >> N;

    // solve
    memset(dp, -1, sizeof(long long) * MAX_SIZE);
    count(N);

    // output
    cout << dp[N];

    return 0;
}