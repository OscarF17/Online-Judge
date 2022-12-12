#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <tuple>

using namespace std;

int main() {
    ifstream file1, file2;
    string l1, l2;
    file1.open("11044A.out"); // El mio
    file2.open("11044.out"); // Correcto
    int line = 1;
    vector<tuple<int, string, string>> diferencias;

    while (getline(file1, l1) && getline(file2, l2)) {
        if(l1 != l2) {
            diferencias.push_back(make_tuple(line, l1, l2));
        }

        line++;
    }

    if(diferencias.size() != 0) {
        for(int i = 0; i < diferencias.size(); i++) {
            cout << "Error en linea " << get<0>(diferencias[i]) << endl;
            cout << "X >> " << get<1>(diferencias[i]) << endl;
            cout << "O >> " << get<2>(diferencias[i]) << endl;
            cout << endl;
        }
    }
    





    return 0;
}