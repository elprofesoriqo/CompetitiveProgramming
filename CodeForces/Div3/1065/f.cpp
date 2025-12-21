#include <bits/stdc++.h>
using namespace std;

void solution(int n, vector<int> p) {
    p.insert(p.begin(), 0);
    vector<int> pre(n + 1, n + 1);
    vector<pair<int, int>> suf(n + 2, {0, 0});

    pre[0] = n + 1;
    for(int i = 1; i <= n; i++){
        pre[i] = min(pre[i-1], p[i]);
    }

    for(int i = n; i >= 1; i--){
        suf[i] = max(suf[i+1], {p[i], i});
    }

    for(int i = 2; i <= n; i++){
        if(pre[i-1] > suf[i].first){
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;;
    for(int l = 1; l <= n;){
        int r = suf[l].second;

        for(int i = l; i < r; i++) {
            cout << p[i] << ' ' << p[r] << endl;
        }

        if(l > 1) cout << pre[l-1] << ' ' << p[r] << endl;
        l = r + 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++) cin >> p[i];

        solution(n,p);
    }
    return 0;
}