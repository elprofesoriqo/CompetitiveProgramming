#include <bits/stdc++.h>
using namespace std;

void solve(int n, int y, int r) {
    int num = 0;
    num += r;

    if (num>=n) {
        cout<<n<<endl;
    }else {
        num+=y/2;
        if (num>=n) {
            cout<<n<<endl;
        }else {
            cout<<num<<endl;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n,y,r;
        cin >> n >> y >> r;
        solve(n,y,r);
    }
    return 0;
}