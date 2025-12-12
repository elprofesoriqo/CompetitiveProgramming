#include <bits/stdc++.h>
using namespace std;

void solution(int n, vector<int> v) {
    int maxx = v[0];
    int rem=0;

    for(int i=1;i<n;i++) {
        if (v[i] >= maxx) {
            maxx = v[i];
        }else {
            rem++;
        }
    }


    cout<<rem<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        solution(n, v);
    }
    return 0;
}