#include <bits/stdc++.h>
using namespace std;

void solution(int n, vector<int>& p) {
    long long good_cnt=0;

    for (int i = 0; i < n-1; i++)
        if (abs(p[i]-p[i+1]) == std::gcd(p[i], p[i+1])) good_cnt++;

    cout << good_cnt << endl;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++) cin >> p[i];
        solution(n, p);
    }
}