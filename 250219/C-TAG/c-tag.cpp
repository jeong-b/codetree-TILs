#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int N, M, answer = 0;
vector<int> comb;
vector<string> groupA, groupB;
unordered_set<string> keyA, keyB;

void generate_combinations(int start) {
    if (comb.size() == 3) {
        //cout << comb[0] << comb[1] << comb[2] << '\n';
        keyA.clear();
        keyB.clear();
        for (int i = 0; i < N; ++i) {
            string A, B;
            A.push_back(groupA[i][comb[0]]);
            A.push_back(groupA[i][comb[1]]);
            A.push_back(groupA[i][comb[2]]);
            B.push_back(groupB[i][comb[0]]);
            B.push_back(groupB[i][comb[1]]);
            B.push_back(groupB[i][comb[2]]);
            keyA.insert(A);
            keyB.insert(B);
            //cout << A << ' ' << B << '\n';
            if(keyA.find(B) != keyA.end() || keyB.find(A) != keyB.end()) return;
        }
        //cout << 't';
        ++answer;
        return;
    }

    for (int i = start; i < M; ++i) { 
        comb.push_back(i);
        generate_combinations(i + 1);
        comb.pop_back();
    }
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> N >> M;
    groupA.resize(N);
    groupB.resize(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> groupA[i];
    }

    for (int i = 0; i < N; ++i) {
        cin >> groupB[i];
    }

    generate_combinations(0);

    cout << answer;

	return 0;
}