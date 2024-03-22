#include <iostream>
#include <climits>

#define MAX_N 100000

using namespace std;

// 변수 선언
int n, k;
int arr[MAX_N + 1];
int prefix_sum[MAX_N + 1];
int ans = INT_MIN;

// [s, e] 구간 내의 원소의 합을 반환합니다.
int GetSum(int s, int e) {
    return prefix_sum[e] - prefix_sum[s - 1];
}

int main() {
    // 입력:
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];

    // 누적합 배열을 만들어줍니다.
    prefix_sum[0] = 0;
    for(int i = 1; i<= n; i++)
        prefix_sum[i] = prefix_sum[i - 1] + arr[i];
    
    // 모든 구간에 대해 합을 찾아
    // 그 중 최댓값을 갱신합니다.
    for(int i = 1; i <= n - k + 1; i++)
        ans = max(ans, GetSum(i, i + k - 1));

    cout << ans;
    return 0;
}