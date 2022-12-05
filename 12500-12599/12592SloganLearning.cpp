#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, string> slogans;

int main() { 
    string input;
    int n;
    getline(cin, input);
    n = stoi(input);
    for(int i = 0; i < n; i++) {
        getline(cin, input);
        string slogan = input;
        getline(cin, input);
        slogans[slogan] = input;
    }
    getline(cin, input);
    n = stoi(input);
    for(int i = 0; i < n; i++) {
        getline(cin, input);
        cout << slogans[input] << endl;
    }
    return 0;
}