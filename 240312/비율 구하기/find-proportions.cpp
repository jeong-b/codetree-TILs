#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, int> m;
    for (int i = 0; i < n; i++) {
        string key;
        cin >> key;

        if (m.find(key) != m.end()) m[key]++;
        else m.insert({ key, 1 });
    }

    map<string, int>::iterator it;
    for(it = m.begin(); it != m.end(); it++) {
        double rate = ((double)(it -> second) / (double)n) * 100;
        cout << fixed;
        cout.precision(4);
        cout << (it -> first) << " " << rate << endl;
    }
    
    return 0;
}