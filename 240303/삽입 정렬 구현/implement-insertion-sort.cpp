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

    for(int i = 1; i < n; i++) {
        int key = answer[i];
        int j = i - 1;
        while(j >= 0 && answer[j] > key) {
            answer[j + 1] = answer[j];
            answer[j] = key;
            j--;
        }
    }

    for(int i = 0; i < n; i++) {
        cout << answer[i] << ' ';
    }

    return 0;
}