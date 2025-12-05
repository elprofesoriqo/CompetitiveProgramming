#include <bits/stdc++.h>
using namespace std;

void solution(int n, vector<long long> a, vector<long long> b) {
    long long min_k = 0;
    long long max_score = 0;

    for(int i=0; i<n; i++) {
        long long red = max_score - a[i];
        long long blue = min_k - a[i];
        long long next_max = b[i] - max_score;
        long long next_min = b[i] - min_k;

        max_score = max({red, blue, next_max, next_min});
        min_k = min({red, blue, next_max, next_min});
    }
    cout << max_score << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        vector<long long> a(n);
        vector<long long> b(n);
        for (int i = 0; i < n; i++) {
            cin>>a[i];
        }
        for (int i = 0; i < n; i++) {
            cin>>b[i];
        }
        solution(n,a,b);
    }

}