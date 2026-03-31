#include <bits/stdc++.h>
using namespace std;

void solution(int n, long long k, vector<long long>& a) {
    long long trucks = 0;
    vector<long long> x = a;

    priority_queue<pair<long long, int>> pq;
    for(int i = 0; i < n; i++) pq.push({x[i], i});

    while(!pq.empty()) {
        long long h = pq.top().first;
        int s = pq.top().second;
        pq.pop();

        if (h < x[s]) continue;
        if (s > 0 && x[s - 1] < h - k) {
            x[s - 1] = h - k;
            pq.push(make_pair(x[s - 1], s - 1));
        }
        if (s < n - 1 && x[s + 1] < h - k) {
            x[s + 1] = h - k;
            pq.push(make_pair(x[s + 1], s - 1 + 2));
        }
    }

    for (int i = 0; i < n; i++) trucks += (x[i] - a[i]);

    cout << trucks << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    solution(n, k, a);
    return 0;
}