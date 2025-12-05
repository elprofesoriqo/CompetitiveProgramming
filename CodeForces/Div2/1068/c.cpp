#include <bits/stdc++.h>
using namespace std;

bool is_valid(int val, int k, int n, const vector<int>& a) {
    if ((long long)k / val > n) {
        return false;
    }
    for (long long i = val; i <= k; i += val) {
        if (!binary_search(a.begin(), a.end(), i)) {
            return false;
        }
    }
    return true;
}

void solution(int n, int k, vector<int>& a) {
    vector<int> b;
    vector<int> check;

    for (int i : a) {
        if (is_valid(i, k, n, a)) {
            check.push_back(i);
        }
    }

    vector<bool> removed(check.size(), false);
    for (int i = 0; i < check.size(); i++) {
        if (removed[i]) continue;
        b.push_back(check[i]);
        long long val = check[i];
        if ((long long)k / val > n) continue;
        for (long long j = val * 2; j <= k; j += val) {
            if (j > check.back()) break;
            auto it = lower_bound(check.begin(), check.end(), (int)j);
            if (it != check.end() && *it == (int)j) {
                removed[it - check.begin()] = true;
            }
        }
    }

    vector<bool> is_covered(n, false);
    int covered_count = 0;

    for (int i : b) {
        if ((long long)k / i > n) {
        }
        for (long long j = i; j <= k; j += i) {
             if (j > a.back()) break;
             auto it = lower_bound(a.begin(), a.end(), (int)j);
             if (it != a.end() && *it == (int)j) {
                 int idx = it - a.begin();
                 if (!is_covered[idx]) {
                     is_covered[idx] = true;
                     covered_count++;
                 }
             }
        }
    }

    if (covered_count == n) {
        cout << b.size() << endl;
        for (int i = 0; i < b.size(); i++) {
            cout << b[i] << (i < b.size() - 1 ? " " : "");
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        n = a.size();
        solution(n, k, a);
    }
}