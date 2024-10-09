#include <iostream>
#include <cstring>

#define MAX_SIZE 1001

using namespace std;

int dp[MAX_SIZE];
int N;

int count(int num) {
    if (dp[num] != -1) { return dp[num]; }

    if (num == 1) { dp[num] = 1; }
    else if (num == 2) { dp[num] = 3; }
    else { dp[num] = (count(num - 1) + (count(num - 2) * 2)) % 10007; }

    return dp[num];
}


int main() {
    cin >> N;

    memset(dp, -1, sizeof(int) * MAX_SIZE);
    count(N);

    cout << dp[N];

    return 0;
}