#include <bits/stdc++.h>
using namespace std;

void solution(int n, vector<string> a) {
    string s = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] + s < s + a[i]) {
            s = a[i] + s;
        } else {
            s += a[i];
        }
    }

    cout << s << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin>>n;
        vector<string> a(n);
        for(int i=0;i<n;i++) cin>>a[i];

        solution(n,a);
    }
    return 0;
}