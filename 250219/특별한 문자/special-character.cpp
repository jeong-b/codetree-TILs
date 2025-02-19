#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    
    string word;
    cin >> word;

    unordered_map<char, int> wordCount;
    for(char a : word) {
        wordCount[a]++;
    }

    for(char a : word) {
        if(wordCount[a] == 1) {
            cout << a;
            return 0;
        }
    }

    cout << "None";

	return 0;
}