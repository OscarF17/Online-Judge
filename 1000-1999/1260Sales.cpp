#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;
    for(int i = 0; i < T; i++) {
        int n, x;
        cin >> n;
        vector<int> A(n);
        int acum = 0;
        cin >> x;
        A[0] = x;
        for(int j = 1; j < n; j++) {
            cin >> x;
            A[j] = x;
            for(int k = j-1; k >= 0; k--) {
                if(A[k] <= A[j])
                    acum++;
            }
        }
        cout << acum << endl;
    }
    return 0;
}
