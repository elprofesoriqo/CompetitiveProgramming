#include <bits/stdc++.h>
using namespace std;

void solution(int n, int x1, int x2, int k) {
    if (n <= 3) cout << min(abs(x1 - x2), n-abs(x1-x2));
    else cout << min(abs(x1 - x2), n-abs(x1-x2)) + k;
    cout<<"\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, x1, x2, k;
        cin >> n >> x1 >> x2>>k;
        solution(n,x1,x2,k);
    }
}