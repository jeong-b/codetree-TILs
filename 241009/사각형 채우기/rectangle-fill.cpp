#include <iostream>
#include <cstring>

#define MAX_SIZE 1000

using namespace std;

int square[MAX_SIZE];
int N;

int count(int num) {
    if (square[num] != -1) {
        return square[num];
    }
    if (num <= 1) {
        square[num] = 1;
    }
    else {
        square[num] = (count(num - 1) + count(num - 2)) % 10007;
    }

    return square[num];
}

int main() {
    // input
    cin >> N;

    // solve
    memset(square, -1, sizeof(int) * N);
    count(N);

    // output
    cout << square[N];

    return 0;
}