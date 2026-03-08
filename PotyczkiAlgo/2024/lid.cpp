#include <bits/stdc++.h>
using namespace std;

void solution(int n, vector<int> &a) {
    sort(a.begin()+1, a.end(), greater<int>());
    int k=0; //numlist
    int l=1, r=n;

    while (l<=r) {
        int can = a[l] - 1;
        while (can > 0 && l < r) {
            int take = min(a[r], can);
            a[r] -= take;
            can -= take;
            if (a[r] == 0) r--;
        }
        k++;
        l++;
    }
    cout<<k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n+1,0);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }


    solution(n,a);
    return 0;
}