#include <bits/stdc++.h>
using namespace std;

void solution(int n, vector<int>& a) {
    vector<pair<int, int>> a_sort(n);
    for (int i = 0; i < n; i++) a_sort[i] = {a[i], i};

    sort(a_sort.rbegin(), a_sort.rend());
    vector<int> diff(n + 1, 0);

    vector<int> prev_idx(n), next_idx(n);
    for (int k = 0; k < n; k++) {
        prev_idx[k] = (k - 1 + n) % n;
        next_idx[k] = (k + 1) % n;
    }

    int actv_size = n;
    int i = n - 1;
    while (i >= 0) {
        int j = i;
        while (j >= 0 && a_sort[j].first == a_sort[i].first) j--;
        for (int k = i; k > j; k--) {
            int idx = a_sort[k].second;

            if (actv_size == 1) {
                diff[0]++;
                diff[n]--;
            } else {
                int idx_l = prev_idx[idx];

                int cut_l = (idx_l + 1) % n;
                int cut_r = idx;

                if (cut_l <= cut_r) {
                    diff[cut_l]++;
                    diff[cut_r + 1]--;
                } else {
                    diff[0]++;
                    diff[cut_r + 1]--;
                    diff[cut_l]++;
                    diff[n]--;
                }
            }
        }
        for (int k = i; k > j; k--) {
            int idx = a_sort[k].second;
            next_idx[prev_idx[idx]] = next_idx[idx];
            prev_idx[next_idx[idx]] = prev_idx[idx];
            actv_size--;
        }
        i = j;
    }

    int zachwyt = 0;
    int curr_z = 0;
    for (int k = 0; k < n; k++) {
        curr_z += diff[k];
        zachwyt = max(zachwyt, curr_z);
    }

    cout << zachwyt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    solution(n,a);

    return 0;
}