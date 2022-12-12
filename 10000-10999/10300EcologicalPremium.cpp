#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int farmers;
        cin >> farmers;
        long long int total = 0;
        for(int j = 0; j < farmers; j++) {
            long long int sizeFarm, numAnimals, envFr;
            cin >> sizeFarm >> numAnimals >> envFr;
            total += sizeFarm*envFr;   
        }
        cout << total << endl;
    }

    return 0;
}