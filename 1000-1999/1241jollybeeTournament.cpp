//1241 online judge
#include <iostream>
#include <sstream>
#include <bitset>
#include <cmath>

using namespace std;

int main() {
    bitset<1024> B; //Tener un bitset listo para todos los particpantes que pueden haber
    B.set(); //Asumir que todos los particpantes vienen
    int cases, n, m, participants, aux, step, wo;
    cin >> cases;
    for(int i = 0; i<cases; i++) {
        wo=0;
        cin >> n >> m;
        participants=pow(2,n);
        for(int j=0; j<m; j++) { //Leer ausentes
            cin >> aux;
            B[aux-1]=0; //No me interesa tener la posición 0, empezaré desde la posición 0 como 1
        }
        step=1;
        while(step!=participants) {
            for(int j=0; j<=(participants-2); j+=step*2) {
                if(B[j] xor B[j+step])
                    wo++;
                if(B[j] | B[j+step])
                    B[j]=1;
                else
                    B[j]=0;
            }
            step*=2;
        }
        cout << wo << endl;

        B.set();

    }
    return 0;
}