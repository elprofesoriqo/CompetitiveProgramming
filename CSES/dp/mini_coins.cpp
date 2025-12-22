#include <bits/stdc++.h>
using namespace std;

void solution(int n, int sum, vector<int>& coins) {
    vector<int> dp(sum + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= sum; i++) {
        for (int coin: coins) {
            if (i - coin >= 0) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    if (dp[sum] == 1e9) {
        cout << -1 << endl;
    } else {
        cout << dp[sum] << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];
    solution(n,x,coins);
    return 0;
}