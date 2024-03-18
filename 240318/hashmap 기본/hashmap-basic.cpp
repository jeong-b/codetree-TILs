#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
	/* 변수 지정 */
	int n; // 명령 개수 int n
	unordered_map<int, int> um; // 값을 저장하는 unordered_map<int, int> um
	string cmd; // 명령어 string cmd - add: 추가, remove - 삭제, find - 탐색
	int k, v; // 명령어와 함께 입력되는 key, value값을 나타내는 int k, v

	/* 변수 입력 */
	cin >> n;
	for (int i = 0; i < n; i++)
	{
        cin >> cmd;

        if (cmd == "add")
        {
            cin >> k >> v;
            um[k] = v;
        }
        else if (cmd == "remove")
        {
            cin >> k;
            um.erase(k);
        }
        else if (cmd == "find") 
        {
            cin >> k;
            if (um.find(k) == um.end()) cout << "None" << endl;
            else cout << um[k] << endl;
        }
	}

	return 0;
}