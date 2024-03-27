#include <iostream>

using namespace std;

int main() {
    int a, b, max;
    cin >> a >> b;
    max =  a < b ? b : a;
    cout << max;
	return 0;
}