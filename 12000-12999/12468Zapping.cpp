#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    while(a != -1 && b != -1) {
        if(a == b)
            cout << "0" << endl;
        else {
            // Forward
            int forward;
            if(a < b)
                forward = b-a;
            else 
                forward = 99-a + b+1;
            // Backward
            int backward;
            if(a > b)
                backward = a-b;
            else
                backward = a+1 + 99-b;
            //cout << forward << " " << backward << endl;
            cout << min(forward, backward) << endl;
        }

        cin >> a >> b;
    }
    return 0;
}