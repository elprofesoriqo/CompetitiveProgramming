#include <bits/stdc++.h>
using namespace std;

void solution(int n, vector<int>& w) {
    vector<int> cnts(3, 0);
    int max_op = 0;

    for (int i = 0; i < n; i++) {
        if (w[i] == 0) max_op++;
        else if (w[i] == 1) cnts[1]++;
        else if (w[i] == 2) cnts[2]++;
    }
    int full = min(cnts[1], cnts[2]);
    max_op += full;
    cnts[1] -= full;
    cnts[2] -= full;

    max_op += cnts[1] / 3;
    max_op += cnts[2] / 3;

    cout << max_op << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> w(n);
        for (int i = 0; i < n; i++) cin >> w[i];
        solution(n, w);
    }
}