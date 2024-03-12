#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, int> m;
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;

        if(m.find(word) != m.end()) m[word]++;
        else m.insert({ word, 1 });
    }

    map<string, int>::iterator it;
    for(it = m.begin(); it != m.end(); it++) {
        cout << (it -> first) << " " << (it -> second) << endl;
    }
    
    return 0;
}