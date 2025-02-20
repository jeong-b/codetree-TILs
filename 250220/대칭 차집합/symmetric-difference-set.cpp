#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int numberOfA, numberOfB;
    cin >> numberOfA >> numberOfB;

    unordered_set<int> groupA, groupB, intersection;

    for (int i = 0; i < numberOfA; ++i) {
        int element;
        cin >> element;
        groupA.insert(element);
    }
    for (int i = 0; i < numberOfB; ++i) {
        int element;
        cin >> element;
        groupB.insert(element);
        if (groupA.find(element) != groupA.end()) {
            intersection.insert(element);
        }
    }

    int answer = 0;
    for(const auto& e : groupA) {
        if(intersection.find(e) != intersection.end()) continue;
        ++answer;
    }
    for(const auto& e : groupB) {
        if(intersection.find(e) != intersection.end()) continue;
        ++answer;
    }

    cout << answer;

	return 0;
}