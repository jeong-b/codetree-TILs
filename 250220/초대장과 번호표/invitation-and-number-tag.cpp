#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int N, G;
    cin >> N >> G;

    vector<unordered_set<int>> groupMembers(G);
    unordered_map<int, unordered_set<int>> personGroups;
    unordered_map<int, int> groupRemaining;
    unordered_set<int> invited;
    queue<int> q;

    for (int i = 0; i < G; ++i) {
        int groupSize;
        cin >> groupSize;
        groupRemaining[i] = groupSize;

        for (int j = 0; j < groupSize; ++j) {
            int person;
            cin >> person;

            groupMembers[i].insert(person);
            personGroups[person].insert(i);
        }
    }

    invited.insert(1);
    q.push(1);

    while(!q.empty()) {
        int person = q.front();
        q.pop();

        for (int g : personGroups[person]) {
            if (groupRemaining[g] == 0) continue;

            groupMembers[g].erase(person);
            groupRemaining[g]--;

            if (groupRemaining[g] == 1) {
                int remainingPerson = *groupMembers[g].begin();
                if (invited.find(remainingPerson) == invited.end()) {
                    invited.insert(remainingPerson);
                    q.push(remainingPerson);
                }
            }
        }
    }
    
    cout << invited.size();

	return 0;
}