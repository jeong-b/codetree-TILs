#include <iostream>

using namespace std;

int main() {
    char input;
    cin >> input;

    if(input == 'S') cout << "Superior";
    else if(input == 'A') cout << "Excellent";
    else if(input == 'B') cout << "Good";
    else if(input == 'C') cout << "Usually";
    else if(input == 'D') cout << "Effort";
    else cout << "Failure";

	return 0;
}