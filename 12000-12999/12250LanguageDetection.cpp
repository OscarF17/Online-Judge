#include <iostream>
#include <string>
#include <map>

using namespace std;



int main() { 
    string s;
    cin >> s;
    int cases = 1;
    while(s != "#") {
        string lang;
        if(s == "HELLO") 
            lang = "ENGLISH";
        else if(s == "HOLA")
            lang = "SPANISH";
        else if (s == "HALLO")
            lang = "GERMAN";
        else if(s == "BONJOUR")
            lang = "FRENCH";
        else if(s == "CIAO")
            lang = "ITALIAN";
        else if(s == "ZDRAVSTVUJTE")
            lang = "RUSSIAN";
        else
            lang = "UNKNOWN";
        cout << "Case " << cases << ": " << lang << endl;
        cases++;
        cin >> s;
    }
    return 0;
}