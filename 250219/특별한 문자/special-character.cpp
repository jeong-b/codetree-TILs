#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string word;
    cin >> word;

    int wordCount[26] = {0};  // 알파벳 개수만큼 배열 생성

    for(char c : word) {
        wordCount[c - 'a']++;  // 알파벳 카운트
    }

    for(char c : word) {
        if(wordCount[c - 'a'] == 1) {
            cout << c << '\n';  // 개행 추가
            return 0;
        }
    }

    cout << "None\n";  // 개행 추가
    return 0;
}
