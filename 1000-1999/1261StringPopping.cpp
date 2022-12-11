/*
Oscar Flores 570390
Eduardo Flores 568379
Damos nuestra palabra de haber realizado esta actividad con Integridad Académica
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// Queremos recordar si una cadena en particular ya se hizo y si esta se pudo o no resolver
// Una matriz con arreglos sería complicado porque necesitariamos navegarla hasta encontrar la cadena que queremos, usar un mapa
map<string, bool> m;

// Revisar su una palabra ya esta en el mapa
bool check(string line) {
    bool r = true;
    try {
        if(m.at(line))
            r = true;
    }
    catch (const out_of_range& oor) {
        r = false;
    }
    return r;
}

// Devolver vector con los grupos de letras
vector<string> getGroups(string line) {
    vector<string> groups;
    string group = "";
    char last = line[0];
    group += last;
    for(int i = 1; i < line.size(); i++) {
        if(line[i] == last)
            group += last;
        else {
            groups.push_back(group);
            group = "";
            group += line[i];
        }
        last = line[i];
    }
    groups.push_back(group);
    return groups;
}

bool cut(string line) {
    if(line == "")
        return true;
    if(line.size() == 1)
        return false;

    // Si ya esta en el mapa, devuelve su valor
    if(check(line))
        return m[line];

    bool res = false;
    
    // Obtener grupos
    vector<string> groups = getGroups(line);

    // Si solo se tiene un grupo que se puede quitar, true
    if(groups.size() == 1 && groups[0].size() >= 2)
        return true;
    /* if (groups.size() == 1 && groups[0].size() < 2)
        return false; */
    
    string newWord = "";
    // Intentar todas las comibnaciones quitando un grupo
    for(int i = 0; i < groups.size(); i++) {
        if(groups[i].size() >= 2) {
            for(int j = 0; j < groups.size(); j++) {
                if(i != j)
                newWord += groups[j];
            }
            //cout << newWord << endl;
            bool res = cut(newWord);
            m[newWord] = res;
            newWord = "";
            if(res)
                return true;
        }
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    string line;
    for(int i = 0; i < T; i++) {
        cin >> line;
        //cout << "ORIGINAL: " << line << endl;
        if(cut(line))
            cout << "1" << endl;
        else
            cout << "0" << endl;
        m.clear();
    }
    return 0;
}