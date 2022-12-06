/*
Eduardo Flores 568379
Oscar Flores 573090
Damos nuestra palabra de hemos realizado esta actividad con Integridad Académica
*/

#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

int C;
int n;
vector<int> numbers;
vector<bool> solution;
vector<vector<int>> answers;
set<vector<int>> checkAnswers;

// Funcion para modificar el orden de sort()
bool myFunction(int& a, int& b) {
    return a>b;
}

bool vectorSort(vector<int>& a, vector<int> & b) {
    int s = min(a.size(), b.size());
    for(int i = 0; i < s; i++) {
        if(a[i] != b[i])
            return a>b;
    }
}

void solve(int index, int sum) {
    
    // Revisar si tengo una solucion
    if(sum == C) {
        vector<int> aux;
        // Guardar numeros pertenecientes a la solucion en un arreglo
        for(int i = 0; i < n; i++) {
            if(solution[i]) {
                aux.push_back(numbers[i]);
            }
        }
        // Ordenar arreglo de mayor a menor
        sort(aux.begin(), aux.end(), myFunction);
        // Verificar si esta solucion existe, si no, guardarla
        if(checkAnswers.find(aux) == checkAnswers.end()) {
            checkAnswers.insert(aux);
            answers.push_back(aux);
        }
        return;
    }

    // Casos invalidos
    if(index >= n || sum > C) {
        return;
    }

    // Resolver
    solution[index] = true;
    sum += numbers[index];
    solve(index+1, sum);
    solution[index] = false;
    sum -= numbers[index];
    solve(index+1, sum);


}

int main() {
    
    int input;
    cin >> C;
    cin >> n;
    while(n != 0) {
        numbers.clear();
        solution.clear();
        answers.clear();
        checkAnswers.clear();
        solution.resize(n, false);

        for(int i = 0; i < n; i++) {
            cin >> input;
            numbers.push_back(input);
        }
        sort(numbers.begin(), numbers.end());
        solve(0, 0);
        if(answers.size() != 0 && answers.size() != 1)
            sort(answers.begin(), answers.end(), vectorSort);
        cout << "Sums of " << C << ":" << endl;
        if(answers.size() != 0) {   
            for(int i = 0; i < answers.size(); i++) {
                for(int j = 0; j < answers[i].size(); j++) {
                    if(j != answers[i].size()-1) 
                        cout << answers[i][j] << "+";
                    else
                        cout << answers[i][j];
                }
                cout << endl;
            }
        }
        else
            cout << "NONE" << endl;
        cin >> C;
        cin >> n;
    }

    return 0;
}
