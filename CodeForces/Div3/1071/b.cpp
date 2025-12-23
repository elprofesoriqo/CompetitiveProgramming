#include <bits/stdc++.h>
using namespace std;

void solution(int n, vector<int>& a) {

    long long sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += abs(a[i] - a[i+1]);
    }

    long long del = max(abs(a[0] - a[1]), abs(a[n-2] - a[n-1]));

    for (int i = 1; i < n - 1; i++) {
        long long saved = (abs(a[i-1] - a[i]) + abs(a[i] - a[i+1])) - abs(a[i-1] - a[i+1]);
        del = max(del, saved);
    }

    cout << sum - del << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        solution(n,a);
    }
    return 0;
}