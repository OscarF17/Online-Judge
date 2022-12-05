/*
UVA Problem 11933 - Splitting numbers
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=626&page=show_problem&problem=3084
*/

#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

int main() {
    bitset<32> o;
    bitset<32> a;
    bitset<32> b;
    int n;
    cin >> n;
    while(n != 0) {
        o = n;        
        a = 0;
        b = 0;
        int count = 1;
        int i = 0;
        while(count <= o.count()) {
            if(o[i] == 1) {
                if(count%2 != 0)
                    a[i] = 1;
                else 
                    b[i] = 1;
                count++;
            }
            i++;
        }
        cout << a.to_ulong() << " " << b.to_ulong() << endl;
        cin >> n;
    }
}