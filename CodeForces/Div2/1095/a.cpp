#include <bits/stdc++.h>
using namespace std;
const int MOD = 676767677;

void solution(int n, vector<int>& a) {
    long long min_cost=0;
    long long cost=0;
    for (int i = 0; i < n; i++) {
        if(a[i]>1) {
            cost = (cost + a[i])%MOD;
            min_cost = cost;
        } else min_cost = (cost+1)%MOD;
    }
    cout << min_cost << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        solution(n, a);
    }
}