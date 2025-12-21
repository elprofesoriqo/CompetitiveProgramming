#include <bits/stdc++.h>
using namespace std;

void solution(int n, int m, int s, vector<bool>& occupied) {
    int i=1;
    int idx=s;
    while(i<=max(n-s, s)) {
        if(idx-i>=1 && !occupied[idx-i]) {
            cout<<idx-i<<endl;
            return;
        }else if(idx+1 <= n && !occupied[idx+i]) {
            cout<<idx+i<<endl;
            return;
        }
        i++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,s;
    cin>>n>>m>>s;
    vector<bool> occupied(n+1, false);
    for (int i=0; i<m; i++) {
        int l,r;
        cin>>l>>r;
        occupied[s]=true;
        for (int j=l; j<=r; j++) {
            occupied[j] = true;
        }
    }
    solution(n,m,s, occupied);
    return 0;
}