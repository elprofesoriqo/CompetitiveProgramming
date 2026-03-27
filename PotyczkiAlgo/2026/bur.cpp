#include <bits/stdc++.h>
using namespace std;

void solution(long long n, vector<int> &a) {
    long long suma = 0;
    for (int i = 0; i < n; i++) suma+= a[i];

    vector<int> div;
    for (long long i = 1; i * i <= suma; i++) {
        if (suma % i == 0) {
            if (i <= n) div.push_back(i);
            if (suma / i != i && (suma / i) <= n) div.push_back(suma / i);
        }
    }

    sort(div.rbegin(), div.rend());
    vector<int> diff(n + 1);
    diff[0] = a[0];
    diff[n] = -a[n - 1];
    for (int i = 1; i < n; i++) diff[i] = a[i] - a[i - 1];

    int k = 1;
    vector<long long> fale(n + 1);

    for (int curr_k : div) {
        bool width = true;
        for (int idx = 0; idx <= n; idx++) {
            fale[idx] = diff[idx];
            if (idx >= curr_k) fale[idx] += fale[idx - curr_k];
            if (fale[idx] < 0) {
                width = false;
                break;
            }
            if (idx > n - k && fale[idx] != 0) {
                width = false;
                break;
            }
        }

        if (width) {
            k = curr_k;
            break;
        }
    }

    cout << k;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    solution(n,a);
    return 0;
}