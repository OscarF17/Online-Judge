#include <iostream>

using namespace std;

int main() {
    int N, B, H, W;
    while(cin >> N) {
        cin >> B >> H >> W;
        bool affordable = false;
        bool available = false;
        int minTotal = -1;
        for(int i = 0; i < H; i++) {
            int p;
            cin >> p;
            // Check if it is affordable
            if(p*N < B) {
                affordable = true;
                for(int j = 0; j < W; j++) {
                    int a;
                    cin >> a;
                    if(a >= N) {
                        available = true;
                    }
                }
            }
            // Read unaffordable
            else {
                for(int j = 0; j < W; j++) {
                    int a;
                    cin >> a;
                }
            }
            if(affordable && available && minTotal == -1)
                minTotal = p*N;
            else if(affordable && available && p*N < minTotal)
                minTotal = p*N;
        }
        if(minTotal == -1)
            cout <<"stay home" << endl;
        else
            cout << minTotal << endl;
    }
    return 0;
}
