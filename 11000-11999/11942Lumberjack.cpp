#include <iostream>

using namespace std;

int main() {
    int N; // Cases
    cin >> N;
    cout << "Lumberjacks:" << endl;
    for(int i = 0; i < N; i++) {
        bool asc = false; // Check if ascending order, least to greater
        int a, b;
        cin >> a;
        cin >> b;
        if(a < b)
            asc = true;
        bool ordered = true;
        for(int j = 0; j < 8; j++) {
            cin >> a;
            if((asc && a < b) || (!asc && a > b)) {
                ordered = false;
            }
            b = a;
        }
        if(ordered)
            cout << "Ordered" << endl;
        else
            cout << "Unordered" << endl;
    }
    return 0;
}
