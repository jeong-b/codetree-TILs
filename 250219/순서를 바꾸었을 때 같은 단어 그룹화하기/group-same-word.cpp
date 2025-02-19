#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int N;
string word;
unordered_map<string, int> wordList;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int answer = 0;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> word;
        sort(word.begin(), word.end());
        wordList[word]++;
        answer = max(answer, wordList[word]);
    }

    cout << answer;

	return 0;
}