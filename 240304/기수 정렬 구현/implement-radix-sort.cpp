#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> answer;
    for(int i = 0; i < n; i++) {
        int input;
        cin >> input;
        answer.push_back(input);
    }

    int pos = 1;
    for(int i = 0; i < 6; i++) { // 최대가 100,000이므로 6자리까지 반복
        vector<vector<int>> arr(10);
        for(int j = 0; j < n; j++) {
            int digit = (answer[j] / pos) % 10;
            arr[digit].push_back(answer[j]);
        }
        int index = 0;
        for(int j = 0; j < 10; j++) {
            int len = (int)arr[j].size();
            for(int k = 0; k < len; k++) {
                answer[index] = arr[j][k];
                index++;
            }
        } 
        pos *= 10;
    }

    for(int i = 0; i < n; i++) {
        cout << answer[i] << ' ';
    }

    return 0;
}