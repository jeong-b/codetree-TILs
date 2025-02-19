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
        keyA.clear();
        keyB.clear();

        for (int i = 0; i < N; ++i) {
            // `substr()`을 사용하여 세 개의 문자 추출
            string A = {groupA[i][comb[0]], groupA[i][comb[1]], groupA[i][comb[2]]};
            string B = {groupB[i][comb[0]], groupB[i][comb[1]], groupB[i][comb[2]]};

            keyA.insert(A);
            keyB.insert(B);

            // `count()`를 사용하여 가독성 향상
            if (keyA.count(B) || keyB.count(A)) return;
        }

        ++answer;
        return;
    }

    for (int i = start; i < M; ++i) { 
        comb.push_back(i);
        generate_combinations(i + 1);
        comb.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    groupA.resize(N);
    groupB.resize(N);

    // `range-based for`를 사용하여 입력 간결화
    for (auto& str : groupA) cin >> str;
    for (auto& str : groupB) cin >> str;

    generate_combinations(0);

    cout << answer << '\n';

    return 0;
}
