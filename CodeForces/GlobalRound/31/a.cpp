#include <bits/stdc++.h>
using namespace std;

void solution(int l, int a, int b) {

    vector<bool> seen(l, false);
    int prize = 0;
    int k=0;
    int curr_prize = (a+k*b)%l;

    while (!seen[curr_prize]) {
        seen[curr_prize] = true;
        prize = max(prize, curr_prize);
        k++;
        curr_prize = (a+k*b)%l;
    }

    cout<<prize<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int l,a,b;

        cin >> l >> a >> b;

        solution(l,a,b);
    }
    return 0;
}