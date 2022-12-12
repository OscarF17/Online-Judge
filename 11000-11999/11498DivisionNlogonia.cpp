#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    while(n != 0) {
        int d1, d2; // Divison point
        cin >> d1 >> d2;
        int x, y; // Coordinates to test
        for(int i = 0; i < n; i++) {
            cin >> x >> y;
            // Check if in a border
            if(x == d1 || y == d2)
                cout << "divisa" << endl;
            // North west
            else if(x < d1 && y > d2)
                cout << "NO" << endl;
            // North east
            else if (x > d1 && y > d2)
                cout << "NE" << endl;
            // South west
            else if (x < d1 && y < d2)
                cout << "SO" << endl;
            // South east
            else if (x > d1 && y < d2)
                cout << "SE" << endl;
        }
        cin >> n;
    }
    return 0;
}