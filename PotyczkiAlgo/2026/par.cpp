#include <bits/stdc++.h>
using namespace std;

void algosia(int a, int b) {
    int a0 = a - 1;
    int b0 = b - 1;
    
    int dist = (b0 - a0 + 1000) % 1000;
    int shift = (dist == 1 || dist == 999) ? 2 : 1;

    int c0 = (a0 + shift) % 1000;
    int d0 = (b0 + shift) % 1000;
    
    cout << c0 + 1 << " " << d0 + 1 << endl;
}

void bajtek(int c, int d) {
    int c0 = c - 1;
    int d0 = d - 1;
    
    int dist = (d0 - c0 + 1000) % 1000;
    
    int shift = (dist == 1 || dist == 999) ? 2 : 1;
    int a0 = (c0 - shift + 1000) % 1000;
    int b0 = (d0 - shift + 1000) % 1000;
    
    cout << a0 + 1 << " " << b0 + 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string kto;
    if (cin >> kto) {
        int x, y;
        cin >> x >> y;
        
        if (kto == "Algosia") algosia(x, y);
        else if (kto == "Bajtek") bajtek(x, y);
    }
    
    return 0;
}