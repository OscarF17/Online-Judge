#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    queue<pair<int, string>> sites;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s;
        int r, max;
        max = 0;
        for(int j = 0; j < 10; j++) {
            cin >> s >> r;
            sites.push(make_pair(r, s));
            if(r > max)
                max = r;
        }
        cout << "Case #" << (i+1) << ":" << endl;
        while(!sites.empty()) {
            if(sites.front().first == max)
                cout << sites.front().second << endl;
            sites.pop();
        }


    }
    return 0;
}