#include <bits/stdc++.h>
using namespace std;

void solve(int n, int* arr) {
    int current_min = n + 1;
    for (int i = 0; i < n - 1; i++) {
        current_min = min(current_min, arr[i]);
        if (current_min == n - i) {
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int* arr = new int[n];

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        solve(n, arr);
        delete[] arr;
    }

    return 0;
}