#include <bits/stdc++.h>
using namespace std;

void solution(int n, vector<int>& a) {
    int l = 0, r = n;
    int val = 0;

    while (l <= r) {
        int mid = (l + r) / 2;

        vector<bool> b(mid, false);
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < n; ++i) {
            if (a[i] < mid && !b[a[i]]) {
                b[a[i]] = true;
            } else pq.push(a[i]);
        }

        int i = 0;
        while (i < mid) {
            if (b[i]) {
                i++;
                continue;
            }
            while (!pq.empty() && pq.top() < 2 * i + 1) pq.pop();

            if (!pq.empty()) {
                pq.pop();
                b[i] = true;
                i++;
            } else break;
        }
        if (i >= mid) {
            val = mid;
            l = mid + 1;
        } else r = mid - 1;
    }

    cout << val << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        solution(n, a);
    }
}