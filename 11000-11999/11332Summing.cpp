#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    while(n != 0) {
        int x = n;
        while(x >= 10) {
            string number = to_string(x);
            int acum = 0;
            for(int i = 0; i < number.size(); i++) {
                char digit = number[i];
                int a = int(digit - '0');
                acum += a;
            }
            x = acum;
        }
        cout << x << endl;
        cin >> n;
    }
    return 0;
}
