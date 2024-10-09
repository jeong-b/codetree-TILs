#include <iostream>
#include <cstring>

#define MAX_SIZE 1000

using namespace std;

int routes[MAX_SIZE];
int N;

int stair (int floor) {
    if (routes[floor] != -1) {
        return routes[floor];
    }
    if (floor <= 1) {
        routes[floor] = 0; 
    }
    else if (floor <= 4) {
        routes[floor] = 1;
    }
    else {
        routes[floor] = (stair(floor - 2) + stair(floor - 3)) % 10007;
    }

    return routes[floor];
    
}

int main() {
    // input
    cin >> N;

    // solve
    memset(routes, -1, sizeof(int) * MAX_SIZE);
    stair(N);

    // output
    cout << routes[N];

    return 0;
}