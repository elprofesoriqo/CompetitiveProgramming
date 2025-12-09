#include <bits/stdc++.h>
using namespace std;

void solution(int n, const vector<int> &zabawki) {
    int l = 0;
    int r = n - 1;

    while (l < n && zabawki[l] == 0) l++;
    while (r >= 0 && zabawki[r] == 0) r--;
    if (l > r) {
        cout << "NIE" << "\n";
        return;
    }
    for (int i = l; i <= r; i++) {
        if (zabawki[i] == 0) {
            cout << "NIE" << "\n";
            return;
        }
    }
    if (l == r) {
        if (zabawki[l] == 1) cout << "TAK" << "\n";
        else cout << "NIE" << "\n";
        return;
    }

    vector<long long> dp[3];

    dp[0].push_back(0);

    for (int i = l; i <= r; i++) {
        vector<long long> next_dp[3];
        long long val_a = zabawki[i];

        for (int k = 0; k < 3; k++) {
            for (long long x_prev : dp[k]) {

                for (int d = 0; d <= 2 - k; d++) {

                    long long x_curr = 2LL * val_a - d - x_prev;

                    if (i < r) {
                        if (x_curr >= 1) {
                            next_dp[k + d].push_back(x_curr);
                        }
                    } else {
                        if (x_curr == 0 && (k + d) == 2) {
                            cout << "TAK" << "\n";
                            return;
                        }
                    }
                }
            }
        }

        bool possible = false;
        for (int k = 0; k < 3; k++) {
            if (!next_dp[k].empty()) {
                possible = true;
                sort(next_dp[k].begin(), next_dp[k].end());
                next_dp[k].erase(unique(next_dp[k].begin(), next_dp[k].end()), next_dp[k].end());
                dp[k] = next_dp[k];
            } else {
                dp[k].clear();
            }
        }

        if (!possible) {
            cout << "NIE" << "\n";
            return;
        }
    }
    cout << "NIE" << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    cin>>t;
    while(t--) {
        cin>>n;
        vector<int> zabawki;
        for(int i=1; i<=n; i++) {
            int a;
            cin>>a;
            zabawki.push_back(a);
        }
        solution(n, zabawki);
    }
    return 0;
}