#include <iostream>
#include <cstring>

#define MAX_SIZE 20

using namespace std;

long long dp[MAX_SIZE];
int N;

long long count(int num) {
    if (dp[num] != -1) { return dp[num]; }

    if (num == 1) { dp[num] = 1; }
    else {
        dp[num] = count(num - 1) * 2;
        for (int i = num - 2; i >= 1; i--) {
            int j = (num - 1) - i;
            dp[num] += count(i) * count(j);
        }
    }

    return dp[num];
}


int main() {
    cin >> N;

    memset(dp, -1, sizeof(long long) * MAX_SIZE);
    count(N);

    cout << dp[N];

    return 0;
}