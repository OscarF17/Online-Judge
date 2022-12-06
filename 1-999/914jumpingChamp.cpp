#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>

using namespace std;



int main() {

    //CRIBA - TENER LOS PRIMOS LISTOS
    //-------------------------------------
    int limit=1000000;
    vector<int> primes;
    vector<bool> status;
    status.resize(limit+1, true); //Son primos hasta que se demuestre lo contrario
    int pivot=2;
    while(pivot<=sqrt(limit)) {
        for(int i=pivot*2; i<=limit; i+=pivot){
            status[i]=false;
        }
        pivot++;
        while(!status[pivot]) {
            pivot++;
        }
    }
    int highestDif=0, dif;
    for(int i=2; i<=limit; i++){
        if(status[i]){ 
            primes.push_back(i);
            if(primes.size()!=1) {
                dif=primes[primes.size()-1]-primes[primes.size()-2];
                if(dif>highestDif)
                    highestDif=dif;
            }
            
        }
    }
    //--------------------------------------------------------------

    /*
    for(int i=0; i<primes.size(); i++)
        cout << primes[i] << " ";
    
    cout << endl;

    for(int i=0; i<differences.size(); i++)
        cout <<differences[i] << " ";
    */

    int cases, l1, l2;
    cin >> cases;
    vector<int> count;
    count.resize(highestDif+1, 0); //Vector para guardar las diferencias


    for(int i=0; i<cases; i++) {
        cin >> l1 >> l2;
        int lb, hb; //limites

        lb=0;
        //Encontrar limite bajo
        //el numero primo que estoy buscando debe ser MAYOR que el limie
        while(!(primes[lb]>=l1)) { //Mientras no sea mayor que el limite menor
            lb++;
        }
        //Encontrar limite de arriba
        hb=primes.size()-1;
        //El numero primo que estoy buscando debe ser MENOR que el limite
        while(!(primes[hb] <= l2)) {
            hb--;
        }
        
        //Contar diferencias
        for(int j=lb; j<hb; j++) {
            count[primes[j+1]-primes[j]]++;
        }

        //Imprimir diferencias
        count[0]=0;
        /*for(int j=0; j<count.size(); j++) {
            cout << count [j] << " ";
        }*/

        //Buscar diferencia más alta
        int jumpingChamp=count[0];
        for(int j=0; j<count.size(); j++) {
            if(count[j]>count[jumpingChamp])
                jumpingChamp=j;
        }

        //Encontrar si se repite
        bool repeat=false;
        for(int j=0; j<count.size(); j++) {
            if(count[j]==count[jumpingChamp] && j!=jumpingChamp)
                repeat=true;
        }

        if(!repeat && (hb-lb+1))
            cout << "The jumping champion is " << jumpingChamp << endl;
        else
            cout << "No jumping champion" << endl;
        
        count.clear();
        count.resize(highestDif+1, 0);

    }

    return 0;

    
}
