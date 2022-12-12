#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> shops;
    int t, n, x;
    cin >> t;
    for(int i = 0; i < t; i++) {
        shops.clear();
        cin >> n;
        for(int j = 0; j < n; j++) {
            cin >> x;
            shops.push_back(x);
        }
        sort(shops.begin(), shops.end());
        int distance = 0;
        for(int j = shops.size()-1; j > 0; j--)
            distance += shops[j]-shops[j-1];

        cout << distance*2 << endl;
    }
    return 0;
}