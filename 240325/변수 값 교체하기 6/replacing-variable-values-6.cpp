#include <iostream>

using namespace std;

int main() {
    int a = 2, b = 6, temp;
    temp = a;
    a = b;
    b = temp;
    cout << a << endl << b;
	return 0;
}