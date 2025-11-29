#include <bits/stdc++.h>
using namespace std;
 
void solve(int n, vector<int> &seq) {
    map<int, int> mp;
    for (int x : seq) {
        mp[x]++;
    }
 
    int sum = 0;
    int odd_freq_count = 0;
 
    for (auto &p : mp) {
        int count = p.second;
        if (count % 2 == 0) {
            sum += 2;
        } else {
            sum += 1;
            odd_freq_count++;
        }
    }
 
    if (mp.size() % 2 != n % 2) {
        if (odd_freq_count == 0) {
 
            sum -= 2;
        }
    }
 
    cout << sum << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> seq(2 * n);
        for (int i = 0; i < 2 * n; i++) {
            cin >> seq[i];
        }
        solve(n, seq);
    }
    return 0;
}