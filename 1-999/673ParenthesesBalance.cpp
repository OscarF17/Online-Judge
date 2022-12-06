/*
Parenthesis Balance 673
https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=614
*/

#include <stack>
#include <string>
#include <iostream>

using namespace std;

int main() {
    stack<char> pila;
    int n;
    string line;
    getline(cin, line);
    n = stoi(line);
    bool result;
    for(int i = 0; i < n; i++) {
        getline(cin, line);
        result = true;
        if(line != "") {
            for(int j = 0; j < line.size(); j++) {
                //Si es un caracter que abre
                if(line[j] == '(' || line[j] == '[') {
                    pila.push(line[j]);
                }

                //Caracter que cierra
                else {
                    if(line[j] == ')') {
                        if(pila.empty()) {
                            result = false;
                            break;
                        }
                        else if(pila.top() != '(') {
                            result = false;
                            break;
                        }
                        else
                            pila.pop();
                    }
                    else if(line[j] == ']') {
                        if(pila.empty()) {
                            result = false;
                            break;
                        }
                        else if(pila.top() != '[') {
                            result = false;
                            break;
                        }
                        else
                            pila.pop();
                    }
                }
            }
        }

        if(!pila.empty()) 
            result = false;

        if(result)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;

        while(!pila.empty())
            pila.pop();
    }
    return 0;
}