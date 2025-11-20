#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int a) {

    if (a % 2 != 0) {
        cout << 0 << endl;
        return;
    }

    int wynik = a/4 +1;
    cout << wynik << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while (t--) {
        int a;
        cin>>a;
        solve(a);
    }




    return 0;
}