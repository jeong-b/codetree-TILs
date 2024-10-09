#include <iostream>
#include <cstring>

#define MAX_SIZE 50

using namespace std;

int numLists[MAX_SIZE];


int fivonacci(int num) {
    if (numLists[num] != -1) {
        return numLists[num];
    }
    if (num <= 2) {
        numLists[num] = 1;
    }
    else {
        numLists[num] = fivonacci(num - 1) + fivonacci(num - 2);
    }

    return numLists[num];
}

int main() {
    // input
    memset(numLists, -1, sizeof(int)* MAX_SIZE);
    int N;
    cin >> N;

    // solve
    numLists[0] = 0;
    fivonacci(N);

    // output
    cout << numLists[N];

    return 0;
}