#include <iostream>
#include <string>

using namespace std;

int matrix[25][25];
int x, y;
int blobs;

void solve(int r, int c) {
    blobs++;
    matrix[r][c] = 0;
    /*
    123
    4X5
    678
    */
    // 1
    if(r > 0 && c > 0 && matrix[r-1][c-1]) {
        solve(r-1, c-1);
    }

    // 2
    if(r > 0 && matrix[r-1][c]) {
        solve(r-1, c);
    }

    // 3
    if(r > 0 && c < y-1 && matrix[r-1][c+1]) {
        solve(r-1, c+1);
    }

    // 4
    if(c > 0 && matrix[r][c-1]) {
        solve(r, c-1);
    }

    // 5
    if(c < y-1 && matrix[r][c+1]) {
        solve(r, c+1);
    }

    // 6
    if(r < x-1 && c > 0 && matrix[r+1][c-1]) {
        solve(r+1, c-1);
    }

    // 7
    if(r < x-1 && matrix[r+1][c]) {
        solve(r+1, c);
    }

    // 8
    if(r < x-1 && c < y-1 && matrix[r+1][c+1]) {
        solve(r+1, c+1);
    }
}

int main() {
    int n;
    string s;
    getline(cin, s);
    n = stoi(s);
    getline(cin, s); // Espacio vacio
    for(int i = 0; i < n; i++) {
        getline(cin, s);
        y = s.size();
        x = 1;
        //cout << s << endl;
        for(int j = 0; j < y; j++) {
            if(s[j] == '1')
                matrix[0][j] = 1;
            else   
                matrix[0][j] = 0;
        }
        getline(cin,s);
        while(s != "") {
            //cout << s << endl;
            for(int j = 0; j < y; j++) {
                if(s[j] == '1')
                    matrix[x][j] = 1;
                else   
                    matrix[x][j] = 0;
            }
            x++;
            getline(cin, s);
        }

        int maxBlobs = 0;
        for(int a = 0; a < x; a++) {
            for(int b = 0; b < y; b++) {
                if(matrix[a][b]) {
                    blobs = 0;
                    solve(a, b);
                    if(blobs > maxBlobs)
                        maxBlobs = blobs;
                }
            }
        }
        cout << maxBlobs << endl;
        if(i != n-1)
            cout << endl;



        /* for(int a = 0; a < x; a++) {
            for(int b = 0; b < y; b++) {
                cout << matrix[a][b];
            }
            cout << endl;
        } */

    }
    
    return 0;
}