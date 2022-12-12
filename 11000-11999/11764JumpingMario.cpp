#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int curr, next;
        cin >> curr;
        int high = 0;
        int low = 0;
        for(int j = 1; j < n; j++) {
            cin >> next;
            if(curr < next)
                high++;
            else if (curr > next)
                low++;
            curr = next;
        }
        cout << "Case " << (i+1) << ": " << high << " " << low << endl;
    }
    return 0;
}