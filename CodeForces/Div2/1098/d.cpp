#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
    bool operator<(const Point& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};

void solution(int n, vector<Point> &P, vector<int>&y) {
    long long colorings = 0;
    vector<int> pref_min(n), pref_max(n);
    pref_min[0] = P[0].y;
    pref_max[0] = P[0].y;

    for (int i = 1; i < n; i++) {
        pref_min[i] = min(pref_min[i-1], P[i].y);
        pref_max[i] = max(pref_max[i-1], P[i].y);
    }

    vector<int> suff_min(n), suff_max(n);
    suff_min[n-1] = P[n-1].y;
    suff_max[n-1] = P[n-1].y;

    for (int i = n - 2; i >= 0; i--) {
        suff_min[i] = min(suff_min[i+1], P[i].y);
        suff_max[i] = max(suff_max[i+1], P[i].y);
    }

    vector<int> has_y(n + 2, 0);
    for (int i = 0; i < n; i++) {
        has_y[P[i].y] = 1;
    }

    vector<int> pref_y(n + 2, 0);
    for (int i = 1; i <= n + 1; i++) {
        pref_y[i] = pref_y[i - 1] + has_y[i];
    }


    for (int i = 0; i < n - 1; i++) {
        if (P[i].x < P[i+1].x) {
            int low = max(pref_min[i], suff_min[i+1]);
            int high = min(pref_max[i], suff_max[i+1]);
            if (low < high) colorings += pref_y[high - 1] - pref_y[low - 1];
        }
    }

    cout << colorings << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >>n;

        vector<Point> P(n);
        vector<int> y(n);

        for (int i = 0; i < n; i++) {
            cin >> P[i].x >> P[i].y;
            y[i] = P[i].y;
        }
        sort(P.begin(), P.end());
        sort(y.begin(), y.end());
        y.erase(unique(y.begin(), y.end()), y.end());
        solution(n,P,y);
    }
}