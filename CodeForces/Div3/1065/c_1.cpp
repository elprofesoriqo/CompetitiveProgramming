#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve(int n, int* a, int* b) {
    int differences = 0;
    int last_difference_index = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            differences++;
            last_difference_index = i;
        }
    }
    if (differences % 2 == 0) {
        cout << "Tie" << endl;
    }else {
        if (last_difference_index % 2 == 0) {
            cout << "Ajisai" << endl;
        } else {
            cout << "Mai" << endl;
        }
    }
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        int* a = new int[n];
        int* b = new int[n];
 
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }
        for (int i = 0; i < n; i++) {
            cin>>b[i];
        }
 
        solve(n, a, b);
        delete[] a;
        delete[] b;
    }
 
    return 0;
}