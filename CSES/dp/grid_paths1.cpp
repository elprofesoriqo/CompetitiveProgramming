#include <bits/stdc++.h>
using namespace std;

void solution(int n, vector<vector<char>> & grid) {
    vector<vector<int>> dp(n, vector<int>(n, 0));
    const int mod = 1e9 + 7;
    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(i==0 && j==0) continue;

            if(grid[i][j]=='*') dp[i][j] = 0;
            else {
                int up = (i > 0) ? dp[i-1][j] : 0;
                int left = (j > 0) ? dp[i][j-1] : 0;
                dp[i][j] = (up + left) % mod;
            }
        }
    }

    cout << dp[n-1][n-1];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cin >> grid[i][j];
    }
    if(grid[n-1][n-1]=='*' || grid[0][0]=='*') cout<<0;
    else solution(n, grid);
    return 0;
}