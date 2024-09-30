// 문제 정보(문제 링크) - 
// 풀이 일시(풀이 시간) - YY. MM. DD (HH:MM:SS)

/* 구현 시나리오 */
/*
* 입력 받는 변수 :
* 출력 하는 변수 :
* 풀이 필요 변수 :
*/

#include <iostream>
#include <vector>

using namespace std;

int n, answer = 0;
vector<int> v;

void Choose(int current)
{
	if (current == n)
	{
		int temp = v[0];
		int cnt = 1;
		bool flag = true;
		for (int i = 0; i < v.size(); i++)
		{
			if (temp == cnt)
			{
				if(i != v.size() - 1) temp = v[i + 1];
				cnt = 1;
				continue;
			}
			if (i != v.size() - 1 && temp == v[i + 1])
			{
				cnt++;
				continue;
			}
			flag = false;
			break;
		}
		if (flag)
		{
			answer++;
		}
		return;
	}

	for (int i = 1; i <= 4; i++)
	{
		v.push_back(i);
		Choose(current + 1);
		v.pop_back();
	}
}

int main()
{
	cin >> n;

	Choose(0);

	cout << answer;

	return 0;
}