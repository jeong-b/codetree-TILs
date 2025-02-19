#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int N, answer = 0;
string word;
unordered_map<string, int> wordCount;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> word;
        sort(word.begin(), word.end());
        answer = max(answer, ++wordList[word]);
    }

    cout << answer;

	return 0;
}