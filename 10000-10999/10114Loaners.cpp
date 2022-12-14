#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Value of car = down payment + amount of loan
    int loanDur, depRecords;
    float downP, loan, carV;
    vector<float> depValues;
    cin >> loanDur;
    while(loanDur > 0) {
        cin >> downP >> loan >> depRecords;

        depValues.resize(loanDur);
        for(int i = 0; i < loanDur; i++)
            depValues[i] = 0;
        carV = downP + loan; // Initial value of the car
        int m;
        float v; // Value for month

        // Read depretiation records
        for(int i = 0; i < depRecords; i++) {
            cin >> m >> v;
            depValues[m] = v;
        }

        for(int i = 0; i < loanDur; i++) {
            if(depValues[i] == 0)
                depValues[i] =  depValues[i-1];
        }

        /* // Print depretiation values
        for(int j = 0; j < depValues.size(); j++) 
            cout << j << ": " << depValues[j] << " " << endl; */

        // Calculate interest for each month
        int ans;
        float payment = loan/loanDur;
        int initLoan = loan;
        for(int i = 0; i < loanDur; i ++) {
            carV = carV - carV*depValues[i];
            loan = initLoan - payment*i;
            if(loan < carV) {
                ans = i;
                //cout << i << ": " << carV << " " << loan << endl;
                break;
            }
        }
        cout << ans << " month";
        if(ans != 1)    
            cout << "s";
        cout << endl;
        
        cin >> loanDur;
    }
    return 0;
}