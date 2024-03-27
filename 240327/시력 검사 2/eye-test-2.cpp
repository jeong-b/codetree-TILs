#include <iostream>

using namespace std;

int main() {
    double num;
    cin >> num;
    if (num >= 1.0) cout << "High";
    else if (num >= 0.5) cout << "Middle";
    else cout << "Low";
	return 0;
}