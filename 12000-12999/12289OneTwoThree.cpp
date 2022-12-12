#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    string input;
    for(int i = 0; i < n; i++) {
        cin >> input;
        // 3
        if(input.size() > 3) 
            cout << "3" << endl;
        // 1
        else if((input[0]=='o' && input[1]=='n') || (input[0]=='o' && input[1]=='e') || (input[2]=='e' && input[1]=='n')) 
            cout << "1" << endl;
        else
            cout << "2" << endl;
    }
    return 0;
}