#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	/* 변수 선언 */
	int n, k; // 원소의 개수 int n, 합을 구하기 위한 원소의 수 int k;
	int input; // 입력 받는 원소 int input
	int answer; // 최댓값을 저장하는 int answer;
	vector<int> num_list, prefix_sum; // 원소를 저장하는  vector<int> num_list, 누적합을 저장하는 vector<int> prefix_sum 
	
	/* 변수 입력 */
	cin >> n >> k;

	cin >> input;
	num_list.push_back(input);
	prefix_sum.push_back(input);

	for (int i = 1; i < n; i++)
	{
		cin >> input;
		num_list.push_back(input);
		prefix_sum.push_back(input + prefix_sum[i - 1]);		
	}

	/* 풀이 */
	answer = prefix_sum[k - 1];
	for (int i = 0; i < n - k; i++) answer = max(answer, prefix_sum[i + k] - prefix_sum[i]);
	
	/* 출력 */
	cout << answer;

	return 0;
}