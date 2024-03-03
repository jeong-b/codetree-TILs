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

    for(int i = 0; i < n -1; i++) {
        int min = i;
        for(int j = i + 1; j < n; j++) {
            if(answer[j] < answer[min]) {
                min = j;
            }
        }
        int temp = answer[i];
        answer[i] = answer[min];
        answer[min] = temp;
    }

    for(int i = 0; i < n; i++) {
        cout << answer[i] << ' ';
    }

    return 0;
}