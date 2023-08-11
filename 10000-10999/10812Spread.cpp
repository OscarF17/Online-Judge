#include <iostream>

using namespace std;

int main() {
    long int n, s, d;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s >> d;
        
        if(d > s)
            cout << "impossible" << endl;
        else {
            long int a, b;
            a = (s+d)/2;
            if((s+d) % 2 != 0) {
                cout << "impossible" << endl;
                continue;
            }
            b = abs(d-a);  
            cout << a << " " << b << endl;
        }
    }
    return 0;
}
