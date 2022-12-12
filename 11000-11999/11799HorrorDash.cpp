#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int max, a;
        cin >> a;
        max = a;
        for(int j = 1; j < n; j++) {
            cin >> a;
            if(a > max)
                max = a;
        }
        cout << "Case " << (i+1) << ": " << max << endl;
    }
    return 0;
}