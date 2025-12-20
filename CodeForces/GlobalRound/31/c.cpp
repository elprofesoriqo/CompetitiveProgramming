#include <bits/stdc++.h>
using namespace std;

void solution(int n, int k) {
    if (k % 2 == 1) {
        for (int i = 0; i < k; i++) {
            cout << n << " ";
        }
        cout << endl;
        return;
    }

    vector<int> a(k, n);
    int ptr = 0;

    for (int i = 29; i >= 0; i--) {
        int bit = 1 << i;
        if (n & bit) {
            if (ptr < k) {
                a[ptr++] ^= bit;
            } else {
                a[0] ^= bit;
            }
        } else {
            for (int j = 0; j + 1 < ptr; j += 2) {
                a[j] ^= bit;
                a[j + 1] ^= bit;
            }
        }
    }

    for (int x : a) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        solution(n, k);
    }
    return 0;
}