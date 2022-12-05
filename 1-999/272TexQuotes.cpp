#include <iostream>
#include <string>

using namespace std;

int main() {
    string original, output;
    bool opening = true;
    while(getline(cin, original)) {
        output = "";
        for(int i = 0; i < original.size(); i++) {
            if(original[i] == '"') {
                if(opening)
                    output += "``";
                else
                    output += "''";
                opening = !opening;
            }
            else {
                output += original[i];
            }
        }
        cout << output << endl;
    }
    return 0;
}