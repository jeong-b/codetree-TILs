#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, G;
    cin >> N >> G;

    vector<unordered_set<int>> group_members(G);  // 각 그룹의 멤버들
    unordered_map<int, unordered_set<int>> person_groups;  // 각 사람이 속한 그룹들
    unordered_map<int, int> group_remaining;  // 각 그룹에서 초대되지 않은 인원 수
    unordered_set<int> invited;  // 초대된 사람 저장
    queue<int> q;  // BFS를 위한 큐

    // 그룹 정보 입력
    for (int g = 0; g < G; ++g) {
        int group_size;
        cin >> group_size;

        for (int j = 0; j < group_size; ++j) {
            int person;
            cin >> person;
            group_members[g].insert(person);
            person_groups[person].insert(g);
        }

        group_remaining[g] = group_size;  // 초기 그룹 멤버 수 저장
    }

    // BFS 초기화 (1번 사람은 무조건 초대받음)
    invited.insert(1);
    q.push(1);

    while (!q.empty()) {
        int person = q.front();
        q.pop();

        // 이 사람이 속한 모든 그룹을 확인
        for (int g : person_groups[person]) {
            if (group_remaining[g] == 0) continue; // 이미 다 초대된 그룹은 무시

            // 초대장을 받은 사람을 그룹에서 제거
            group_members[g].erase(person);
            group_remaining[g]--;

            // 만약 그룹에서 초대되지 않은 사람이 1명만 남았다면 초대해야 함
            if (group_remaining[g] == 1) {
                int remaining_person = *group_members[g].begin();  // 남아있는 사람
                if (invited.find(remaining_person) == invited.end()) {
                    invited.insert(remaining_person);
                    q.push(remaining_person);
                }
            }
        }
    }

    // 초대받은 사람의 수 출력
    cout << invited.size() << '\n';

    return 0;
}
