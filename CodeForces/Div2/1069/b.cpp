#include <bits/stdc++.h>
using namespace std;

void solution(int n, int l, int r) {
    vector<int> pref(n + 1);

    for (int i = 0; i <= n; i++) {
        pref[i] = i + 1;
    }

    pref[r] = pref[l - 1];

    for (int i = 1; i <= n; i++) {
        int a = pref[i] ^ pref[i - 1];
        cout << a << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            int n, l, r;
            cin >> n >> l >> r;
            solution(n, l, r);
        }
    }
    return 0;
}