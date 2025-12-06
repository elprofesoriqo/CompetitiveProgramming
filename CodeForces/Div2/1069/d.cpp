#include <bits/stdc++.h>
using namespace std;

struct State {
    int index;
    long long score;
};

void solution(int n, int k, vector<int>& a) {
    vector<int> row(k + 1, n + 1);
    vector<vector<int>> next(n + 2, row);


    for (int i = n; i >= 1; i--) {
        int capacity = a[i-1];
        for (int v = 1; v <= k; v++) {
            if (capacity >= v) {
                next[i][v] = i;
            } else {
                next[i][v] = next[i+1][v];
            }
        }
    }

    vector<vector<State>> dp(k + 1, vector<State>(k + 1, {-1, -1}));
    dp[0][0] = {0, 0};

    long long max_hap = 0;

    for (int cost = 0; cost <= k; cost++) {
        vector<int> valid_values;
        for (int v = 0; v <= k; v++) {
            if (dp[cost][v].index != -1) {
                valid_values.push_back(v);
            }
        }

        for (int val : valid_values) {
            int current_idx = dp[cost][val].index;
            long long current_hap = dp[cost][val].score;

            max_hap = max(max_hap, current_hap);

            for (int next_val = val + 1; next_val <= k - cost; next_val++) {

                int next_idx = next[current_idx + 1][next_val];

                if (next_idx <= n) {
                    long long added = (long long)(next_val - val) * (n - next_idx + 1);

                    int new_cost = cost + next_val;
                    long long new_score = current_hap + added;

                    if (dp[new_cost][next_val].index == -1 || dp[new_cost][next_val].score < new_score) {
                        dp[new_cost][next_val] = {next_idx, new_score};
                    }
                    else if (dp[new_cost][next_val].score == new_score) {
                        dp[new_cost][next_val].index = min(dp[new_cost][next_val].index, next_idx);
                    }
                }
            }
        }
    }

    cout << max_hap << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        solution(n, k, a);
    }
    return 0;
}