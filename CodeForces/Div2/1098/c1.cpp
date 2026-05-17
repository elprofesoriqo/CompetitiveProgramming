#include <bits/stdc++.h>
using namespace std;

void update(unsigned long long a, unsigned long long val, unsigned long long& min_diff) {
    unsigned long long diff = (a > val) ? (a - val) : (val - a);
    if (diff < min_diff) min_diff = diff;
}

void dfs(int i, int status, unsigned long long val, const string& s, int len_a, const vector<int>& d, unsigned long long a, unsigned long long& min_diff) {
    if (i == len_a) {
        update(a, val, min_diff);
        return;
    }

    if (status == -1) dfs(i + 1, -1, val * 10 + d[1], s, len_a, d, a, min_diff);
    else if (status == 1) dfs(i + 1, 1, val * 10 + d[0], s, len_a, d, a, min_diff);
    else {
        for (int x : d) {
            int next_status = 0;
            if (x < s[i] - '0') next_status = -1;
            if (x > s[i] - '0') next_status = 1;
            dfs(i + 1, next_status, val * 10 + x, s, len_a, d, a, min_diff);
        }
    }
}

void solution(unsigned long long a, int n, vector<int>& d) {
    string s = to_string(a);
    int len_a = s.length();
    unsigned long long min_diff = ULLONG_MAX;

    dfs(0, 0, 0, s, len_a, d, a, min_diff);

    if (len_a > 1) {
        unsigned long long val_short = 0;
        for (int i = 0; i < len_a - 1; i++) val_short = val_short * 10 + d[1];
        update(a, val_short, min_diff);
    }

    unsigned long long val_long = (d[0] == 0 ? d[1] : d[0]);
    for (int i = 0; i < len_a; i++) val_long = val_long * 10 + d[0];
    update(a, val_long, min_diff);
    cout << min_diff << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        long long a,n;
        cin >> a >> n;
        vector<int> d(n);
        for (int i = 0; i < n; i++) cin>>d[i];
        solution(a,n,d);
    }
}