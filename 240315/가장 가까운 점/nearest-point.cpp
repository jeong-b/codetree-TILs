#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Compare
{
    bool operator()(pair<int, int> left, pair<int, int> right)
    {
        if ((abs(left.first) + abs(left.second)) == (abs(right.first) + abs(right.second)))
        {
            if (left.first == right.first) return left.second > right.second;
            return left.first > right.first;
        }
        return (abs(left.first) + abs(left.second)) > (abs(right.first) + abs(right.second));
    }
};

int main() {
    int n, m, x, y;
    priority_queue < pair<int, int>, vector<pair<int, int>>, Compare> pq;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        pq.push(make_pair(x, y));
    }

    for (int i = 0; i < m; i++)
    {
        pair<int, int> temp = make_pair(pq.top().first + 2, pq.top().second + 2);
        pq.pop();
        pq.push(temp);
    }

    cout << pq.top().first << " " << pq.top().second;

    return 0;
}