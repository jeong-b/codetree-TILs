#include <iostream>

using namespace std;

int main() {
    double height;
    int weight, bmi;
    cin >> height >> weight;
    height /= 100;
    bmi = int(weight / (height * height));

    cout << bmi << endl;
    if (bmi >= 25) cout << "Obesity";
    
	return 0;
}