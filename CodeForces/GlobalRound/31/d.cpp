#include <bits/stdc++.h>
using namespace std;

void solution(int n, vector<int> &x) {
    if (n < 2) {
        cout << 0 << endl;
        return;
    }

    vector<long long> diffrences;
    for (int i = 0; i < n - 1; i++) {
        diffrences.push_back(x[i+1] - x[i]);
    }

    long long low = 0;
    long long high = diffrences[0];

    int pairs = 1;

    for (int i = 1; i < diffrences.size(); i++) {
        swap(low, high);
        high = diffrences[i] - high;
        low = diffrences[i] - low;

        if (i < diffrences.size() - 1) {
            high = min(high, (long long)diffrences[i+1]);
        }

        if (low < 0) low = 0;
        if (low >= high) {
            low = 0;
            if (i < diffrences.size() - 1)
                high = diffrences[i+1];
            else
                high = 1e9;
        } else {
            pairs++;
        }
    }
    cout << pairs << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> x(n);
        for (int i = 0; i < n; i++) cin >> x[i];
        solution(n, x);
    }
    return 0;
}