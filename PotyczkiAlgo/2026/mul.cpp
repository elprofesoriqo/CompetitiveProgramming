#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 4000005;
long long fact[MAXN];
long long invFact[MAXN];

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, MOD - 2);
}

void precompute() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAXN; i++) fact[i] = (fact[i - 1] * i) % MOD;
    invFact[MAXN - 1] = modInverse(fact[MAXN - 1]);
    for (int i = MAXN - 2; i >= 1; i--) invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

void solution(long long n, vector<int> &a) {
    bool same = true;
    bool f1 = true;
    bool f2 = true;
    bool f3 = true;
    bool f4 = true;
    
    for (int i = 0; i < 2 * n; i++) {
        if (a[i] != a[0]) same = false;
        if (i % 2 == 0) {
            if (a[i] != 1) f1 = false;
            if (a[i] != 0) f2 = false;
            if (a[i] != 1) f3 = false;
            if (a[i] != 2) f4 = false;
        } else {
            if (a[i] != 0) f1 = false;
            if (a[i] != 1) f2 = false;
            if (a[i] != 2) f3 = false;
            if (a[i] != 1) f4 = false;
        }
    }
    
    if (!same && !f1 && !f2 && !f3 && !f4) {
        cout << 0;
        return;
    }
    
    long long dist = fact[2 * n] * power(modInverse(2), n) % MOD;
    long long total_dist = dist * dist % MOD;
    long long cnt_way = 0;

    if (same && a[0] == 0) cnt_way = nCr(4 * n - 2, 2 * n - 2) * total_dist % MOD;
    else if (same && a[0] == 2) cnt_way = nCr(4 * n - 2, 2 * n) * total_dist % MOD;
    else if (same && a[0] == 1) {
        long long ways = (2 * nCr(4 * n - 3, 2 * n - 1)) % MOD;
        cnt_way = ways * total_dist % MOD;
    } else if (f1 || f2 || f3 || f4) {
        long long ways = nCr(4 * n - 3, 2 * n - 1);
        if (n == 2) cnt_way = 24;
        else cnt_way = (ways * total_dist) % MOD;
    }
    
    cout << cnt_way % MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    precompute();

    int t;
    cin>>t;
    while (t--) {
        long long n;
        cin >> n;
        vector<int> a(2 * n);
        for (int i = 0; i < 2 * n; i++) cin >> a[i];
        solution(n, a);
        cout<<"\n";
    }

    return 0;
}