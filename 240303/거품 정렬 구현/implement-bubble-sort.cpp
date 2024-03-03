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

    bool sorted = true;

    do {
        sorted = true;
        for(int i = 0; i < n - 1; i++) {
            if(answer[i] > answer[i + 1]) {
                int temp = answer[i];
                answer[i] = answer[i + 1];
                answer[i + 1] = temp;
                sorted = false;
            }
        }
    } while (sorted == false);

    for(int i = 0; i < n; i++) {
        cout << answer[i] << ' ';
    }

    return 0;
}