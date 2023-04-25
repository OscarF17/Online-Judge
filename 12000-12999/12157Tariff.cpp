#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T, n; // Cases, number of calls
    cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> n;
        int mtotal = 0;
        int jtotal = 0;
        int call;
        for(int j = 0; j < n; j++) {
            cin >> call;
            int div = call / 30;
            mtotal += 10 + 10*div;
            div = call / 60;
            jtotal += 15 + 15*div;
        }
        cout << "Case " << (i+1) << ": ";
        if(mtotal < jtotal) 
            cout << "Mile " << mtotal << endl;
        else if (jtotal < mtotal)
            cout << "Juice " << jtotal << endl;
        else
            cout << "Mile Juice " << mtotal << endl;
}
    return 0;
}
