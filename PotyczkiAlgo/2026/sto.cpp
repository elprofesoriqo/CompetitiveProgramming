#include <bits/stdc++.h>
using namespace std;

const long long INF = 2e18;

struct SegTree {
    int size;
    vector<long long> tree;

    SegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2 * size, -INF);
    }

    void build(const vector<long long>& a) {
        for (int i = 0; i < (int)a.size(); i++) tree[size + i] = a[i];
        for (int i = size - 1; i > 0; i--) tree[i] = max(tree[2 * i], tree[2 * i + 1]);
    }

    long long query(int l, int r) {
        if (l > r) return -INF;

        long long res = -INF;
        l += size;
        r += size;

        while (l <= r) {
            if (l % 2 == 1) res = max(res, tree[l++]);
            if (r % 2 == 0) res = max(res, tree[r--]);
            l /= 2;
            r /= 2;
        }
        return res;
    }
};

struct BadStack {
    long long total_sum;
    vector<long long> elements;
};

void solution(int n, int m, long long k, const vector<vector<long long> >& a) {
    vector<long long> good;
    vector<BadStack> bad;

    for (int i = 0; i < n; i++) {
        long long sum = 0;
        for (int j = 0; j < m; j++) sum += a[i][j];

        if (m == 1 || a[i][0] >= a[i][m - 1]) {
            for (int j = 0; j < m; j++) good.push_back(a[i][j]);
        } else {
            BadStack bs;
            bs.total_sum = sum;
            bs.elements = a[i];
            bad.push_back(bs);
        }
    }

    sort(good.begin(), good.end(), [](auto a, auto b) {return a > b;});


    int n_good = good.size();
    vector<long long> pref_g(n_good + 1, 0);
    for (int i = 0; i < n_good; i++) pref_g[i + 1] = pref_g[i] + good[i];

    int n_bad = bad.size();
    if (n_bad == 0) {
        if (k <= n_good) cout << pref_g[k] << "\n";
        return;
    }

    sort(bad.begin(), bad.end(), [](const auto& a, const auto& b) {return a.total_sum > b.total_sum;});
    vector<long long> pref_b(n_bad + 1, 0);
    vector<vector<long long> > P(n_bad, vector<long long>(m + 1, 0));

    for (int i = 0; i < n_bad; i++) {
        pref_b[i + 1] = pref_b[i] + bad[i].total_sum;
        for (int j = 0; j < m; j++) P[i][j + 1] = P[i][j] + bad[i].elements[j];
    }

    long long rozm = 0;
    for (int c = 0; c <= n_bad; c++) {
        long long k_rem = k - (long long)c * m;
        if (k_rem >= 0 && k_rem <= n_good) rozm = max(rozm, pref_b[c] + pref_g[k_rem]);
    }

    SegTree tree1(n_bad);
    SegTree tree2(n_bad);
    vector<long long> val1(n_bad), val2(n_bad);

    for (int l = 1; l < m; l++) {
        for (int i = 0; i < n_bad; i++) {
            val1[i] = P[i][l] - bad[i].total_sum;
            val2[i] = P[i][l];
        }

        tree1.build(val1);
        tree2.build(val2);
        for (int c = 0; c < n_bad; c++) {
            long long k_rem = k - (long long)c * m - l;
            if (k_rem >= 0 && k_rem <= n_good) {
                long long best_bad = -INF;

                if (c > 0 && c + 1 <= n_bad) best_bad = max(best_bad, pref_b[c + 1] + tree1.query(0, c - 1));
                best_bad = max(best_bad, pref_b[c] + tree2.query(c, n_bad - 1));
                rozm = max(rozm, best_bad + pref_g[k_rem]);
            }
        }
    }

    cout << rozm;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    long long k;
    cin >> n >> m >> k;
    vector<vector<long long> > a(n, vector<long long>(m));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
    solution(n, m, k, a);
    return 0;
}