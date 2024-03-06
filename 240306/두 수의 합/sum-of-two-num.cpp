#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    double k;
    cin >> n >> k;

    vector<int> num;
    unordered_map<double, int> sum;
    for(int i = 0; i < n; i++) {
        int input;
        cin >> input;

        int j = 0;
        while(i > 0 && j < i) {
            double res = num[j] + input;
            if(sum.find(res) != sum.end()) {
                sum[res]++;
            }
            else {
                sum.insert({res, 1});
            }
            j++;
        }

        num.push_back(input);        
    }

    cout << sum[k];

    return 0;
}