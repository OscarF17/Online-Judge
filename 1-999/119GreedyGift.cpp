#include <iostream>
#include <map>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

map<string, float> totals;

int main() {
    int n;
    string s;
    queue<string> names;
    while(cin >> n) { 
        for(int i = 0; i < n; i++) {
            cin >> s;
            names.push(s);
            totals[s] = 0.0F;
        }

        int given, friends;
        for(int i = 0; i < n; i++) {
            cin >> s; // Leer nombre del amigo
            cin >> given >> friends; // Leer cantidad dada y a cuantos
            if(friends != 0) {
                int each = given / friends;
                int remainder = given - (each*friends);
                totals[s] += remainder;
                totals[s] -= given;
                for(int j = 0; j < friends; j++) {
                    cin >> s;
                    totals[s] += each;
                }
            }
        } 
        while(!names.empty()) {
            cout << names.front() << " " << floor(totals[names.front()]) << endl;
            names.pop();
        }
        cout << endl;
    }

    return 0;
}