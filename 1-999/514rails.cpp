/*
Online Judge 514 Rails
https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=455
*/

#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, car;
    bool result;
    vector<int> coaches;
    vector<int> output;
    stack<int> station;
    cin >> n;
    while(n != 0) {
        cin >> car;
        if(car != 0) {
            result = true;
            coaches.push_back(car);
            for(int j = 0; j < n-1; j++) {
                cin >> car;
                coaches.push_back(car);
            }

            int carIdx = 1; 
            int vIdx = 0; 
            while(output.size() != n) {
                if(carIdx == coaches[vIdx]) {
                    output.push_back(carIdx);
                    carIdx++;
                    vIdx++;
                }

                else if(!station.empty() &&  station.top() == coaches[vIdx]) {
                    output.push_back(station.top());
                    station.pop();
                    vIdx++;
                }

                else if(carIdx <= n) {
                    station.push(carIdx);
                    carIdx++;
                }

                if(carIdx > n) {
                    while(!station.empty()) {
                        output.push_back(station.top());
                        station.pop();
                    }
                }
            }

            
            if(output == coaches) 
                cout << "Yes" << endl;
            else
                cout << "No" << endl;

        }
        else {
            cin >> n;
            cout << endl;
        }

        coaches.clear();
        output.clear();
    }
    return 0;
}