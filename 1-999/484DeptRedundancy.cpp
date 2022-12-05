#include <iostream>
#include <map>
#include <queue>

using namespace std;

map<int, int> numbers;
queue<int> q;

bool checkInMap(int key) {
    bool r = true;
    try {
        if(numbers.at(key))
            r = true;
    }
    catch (const out_of_range& oor) {
        r = false;
    }
    return r;
}

int main() {
    int n;
    while(cin >> n) {
        if(!checkInMap(n)) {
            numbers[n] = 1;
            q.push(n);
        }
        else
            numbers[n]++;
    }
    while(!q.empty()) {
        cout << q.front() << " " << numbers[q.front()] << endl,
        q.pop();
    }
    return 0;
}