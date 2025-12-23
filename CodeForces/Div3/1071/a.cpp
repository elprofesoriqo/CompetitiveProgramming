#include <bits/stdc++.h>
using namespace std;

void solution(int k, int x) {
    int n = k*x;
    cout<<n+1<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int k,x;
        cin >> k >> x;

        solution(k,x);
    }
    return 0;
}