#include <bits/stdc++.h>
using namespace std;

void solution(int n, vector<int>& a) {
    int k = *min_element(a.begin(), a.end());
    vector<int> diff;
    for (int i = 0; i < n; i++) {
        if (a[i]-k ==0) continue;
        diff.push_back(a[i] - k);
    }
    int max_diff = *min_element(diff.begin(), diff.end());

    cout<<max(k, max_diff)<<endl;
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