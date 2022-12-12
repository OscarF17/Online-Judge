#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a  >> b >> c;
        cout << "Case " << (i+1) <<": ";
        if(a <= 20 && b <= 20 && c <= 20)
            cout << "good" << endl;
        else    
            cout << "bad" << endl;
    }
    return 0;
}