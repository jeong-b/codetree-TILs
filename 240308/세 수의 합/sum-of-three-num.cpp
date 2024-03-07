#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    // 변수 입력
    int n, k;
    cin >> n >> k;

    vector<int> num;
    for(int i = 0; i < n; i++) {
        int input;
        cin >> input;
        num.push_back(input);
    }

    int answer = 0;
    for(int i = 0; i < n - 2; i++) {
        int now = num[i];
        int target = k - now;

        unordered_map<int, int> um;
        for(int j = i + 1; j < n; j++) {
            int temp = target - num[j];

            if(um.find(temp) != um.end()) {
                answer += um[temp];
            }

            if(um.find(num[j]) != um.end()) {
                um[num[j]]++;
            }
            else {
                um.insert({num[j], 1});
            }
        }
    }

    cout << answer;

    return 0;
}