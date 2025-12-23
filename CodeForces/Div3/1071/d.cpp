#include <bits/stdc++.h>
using namespace std;

void solution(int n) {
    vector<int> p;
    p.push_back(1);
    p.push_back(0);

    for (int bit = 2; bit <= n; bit++) {
        int current_size = p.size();

        for (int idx = 0; idx < current_size; idx++) {
            p[idx] = (p[idx] << 1) | 1;
        }

        int max_val = 1 << bit;
        for (int num = 0; num < max_val; num++) {
            if (num % 2 == 0) {
                p.push_back(num);
            }
        }
    }

    for (int i = 0; i < p.size(); i++) {
        cout << p[i];
        if (i + 1 < p.size()) cout << " ";
    }
    cout << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        solution(n);
    }
    return 0;
}