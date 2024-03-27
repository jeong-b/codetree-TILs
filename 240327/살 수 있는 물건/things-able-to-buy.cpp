#include <iostream>

using namespace std;

int main() {
    int num;
    cin >> num;
    if (num >= 3000) cout << "book";
    else if (num >= 1000) cout << "mask";
    else cout << "no";
	return 0;
}