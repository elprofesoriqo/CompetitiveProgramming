#include <bits/stdc++.h>
using namespace std;

void solution(int k, vector<vector<int>>& meets) {
    vector<int> need(k + 1, 0);
    vector<int> zw(k + 1, 0);
    vector<vector<int>> dp(k + 1);

    for (int i = 1; i <= k; i++) dp[i] = vector<int>(meets[i].size(), 0);

    for (int i = k; i >= 1; i--) {
        for (int spot = 0; spot < (int)meets[i].size(); spot++) {
            if (dp[i][spot] == 0) {
                dp[i][spot] = 1;
                zw[i]++;
            }
            int prev = meets[i][spot];

            if (prev == 0) need[i] += dp[i][spot];
            else dp[i - 1][prev - 1] += dp[i][spot];
        }
    }

    int cnt_zat = 0;
    int cnt_free = 0;

    for (int i = 1; i <= k; i++) {
        if (need[i] > cnt_free) {
            cnt_zat += (need[i] - cnt_free);
            cnt_free = 0;
        } else cnt_free -= need[i];
        cnt_free += zw[i];
    }
    cout << cnt_zat << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k, n1;
    cin >> k >> n1;
    vector<vector<int>> meets(k + 1);
    meets[1] = vector<int>(n1, 0);

    for (int i = 2; i <= k; i++) {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            meets[i].push_back(x);
        }
    }

    solution(k, meets);
    return 0;
}