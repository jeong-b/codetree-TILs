#include <iostream>

using namespace std;

int main() {
    int num;
    cin >> num;
    if (num >= 100) cout << "vapor";
    else if (num < 0) cout << "ice";
    else cout << "water";
	return 0;
}