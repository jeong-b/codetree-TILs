#include <iostream>
#include <string>
#include <list>

using namespace std;

int main() {
   int n, m;
   cin >> n >> m;

   string toast;
   cin >> toast;

   list<char> bread;
   list<char>::iterator it;

   for(int i = 0; i < n; i++) {
    bread.push_back(toast[i]);
   } 

    it = bread.end();

    for(int i = 0; i < m; i++) {
        char cmd;
        cin >> cmd;

        if(cmd =='L') {
            if(it != bread.begin()) {
                it--;
            }
        }
        else if(cmd == 'R') {
            if(it != bread.end()) {
                it++;
            }
        }
        else if(cmd == 'D') {
            if(it != bread.end()) {
                bread.erase(it++);
            }
        }
        else if(cmd == 'P') {
            char recipe;
            cin >> recipe;
            bread.insert(it, recipe);
        }
    }

    for(it = bread.begin(); it != bread.end(); it++){
        cout << *it;
    }

    return 0;
}