#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> changeSeat(K);
    for (int i = 0; i < K; ++i) {
        cin >> changeSeat[i].first >> changeSeat[i].second;
    }

    vector<unordered_set<int>> seats(N + 1);
    vector<int> current(N + 1);
    for (int i = 1; i <= N; ++i) {
        seats[i].insert(i);
        current[i] = i;
    }

    for (int j = 0; j < 3; ++j) {
        for (int i = 0; i < K; ++i) {
            int a = changeSeat[i].first;
            int b = changeSeat[i].second;

            seats[current[a]].insert(b);
            seats[current[b]].insert(a);

            swap(current[a], current[b]);
            /*
            int temp = current[a];
            current[a] = current[b];
            current[b] = temp;
            */
        }
    }

    for(int i = 1; i <= N; ++i) {
        cout << seats[i].size() << '\n';
    }    

	return 0;
}