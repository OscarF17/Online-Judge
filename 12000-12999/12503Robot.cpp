#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int T, n; // Cases, # of instructions
    cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> n;
        vector<int> moves(n);
        int pos = 0;
        for(int j = 0; j < n; j++) {
            string text;
            int number;
            cin >> text;
            if(text == "LEFT") {
                moves[j] = -1;
                pos--;
            }
            else if (text == "RIGHT") {
                moves[j] = 1;
                pos++;
            }
            else {
                cin >> text; // read AS
                cin >> number;
                moves[j] = moves[number-1];
                pos += moves[j];
            }
        }
        cout << pos << endl;
    }
    return 0;
}
