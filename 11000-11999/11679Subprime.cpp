#include "iostream"
#include <vector>

using namespace std;

int main() {
    int B, N;
    cin >> B >> N;
    while(B && N) { 
        vector<int> reserves(B);        
        for(int i = 0; i < B; i++) 
            cin >> reserves[i];
        for(int i = 0; i < N; i++) {
            int debtor, creditor, value;
            cin >> debtor >> creditor >> value;
            reserves[debtor-1] -= value;
            reserves[creditor-1] += value;
        }
        char output = 'S';
        for(int i = 0; i < B; i++) {
            if(reserves[i] < 0)
                output = 'N';
        }
        cout << output << endl;
        cin >> B >> N;
    } 
    return 0;
}
