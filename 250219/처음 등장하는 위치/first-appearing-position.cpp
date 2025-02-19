#include <iostream>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    
    int N;
    map<int, int> m;

    cin >> N;

    for (int i = 0; i < N; ++i) {
        int input;
        cin >> input;
        m.insert({input, i + 1});
    }

    for (auto it = m.begin(); it != m.end(); ++it) {
        cout << (*it).first << ' ' << (*it).second << endl;
    }

	return 0;
}