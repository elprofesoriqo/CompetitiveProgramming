#include <bits/stdc++.h>
using namespace std;

void solution(long long n, long long q, vector<int>&a) {
    vector<bool> is_prime(n + 1, true);
    if (n >= 0) is_prime[0] = false;
    if (n >= 1) is_prime[1] = false;

    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p]) for (int i = p * p; i <= n; i += p) is_prime[i] = false;
    }
        vector<int> primes;
        for (int p = 2; p <= n; p++) if (is_prime[p]) primes.push_back(p);
        vector<vector<int>> cnt_s(primes.size());
        long long cnt_p = 0;
        for (int i = 0; i <primes.size(); i++) {
            for (int j = 0; j < primes[i]; j++) cnt_s[i].push_back(0);
            cnt_p += primes[i];
        }

        vector<int> zlicz(n + 1, 0);
        zlicz[0] = cnt_p;
        int res = 0;
        int max_s = 0;
        vector<bool> has_s(n + 1, false);
        for (int i = 0; i < q; i++) {
            if (has_s[a[i]]) {
                has_s[a[i]] = false;
                max_s--;
                for (int j = 0; j <primes.size(); j++) {
                    int mod = a[i] % primes[j];
                    int curr_val = cnt_s[j][mod];
                    zlicz[curr_val]--;
                    cnt_s[j][mod]--;
                    zlicz[curr_val-1]++;
                    if (curr_val == res && zlicz[res] == 0) res--;
                }
            } else {
                has_s[a[i]] = true;
                max_s++;
                for (int j = 0; j < primes.size(); j++) {
                    int mod = a[i] % primes[j];
                    int curr_val = cnt_s[j][mod];
                    zlicz[curr_val]--;
                    cnt_s[j][mod]++;
                    zlicz[curr_val + 1]++;

                    if (curr_val + 1 > res) res = curr_val + 1;
                }
            }
                if (primes.empty()) {
                    if (max_s > 0) cout << max_s<<"\n";
                    else cout<< 0 <<"\n";
                } else cout << res << "\n";
        }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n,q;
    cin>>n>>q;
    vector<int> a(q);
    for(int i=0;i<q;i++) cin>>a[i];
    solution(n,q, a);

    return 0;
}