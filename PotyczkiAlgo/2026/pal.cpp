#include <bits/stdc++.h>
using namespace std;

void solution(int n, int k) {
    string word = "";
    word.reserve(n);
    word.append(k, 'P');

    if (k == 1) {
        if (n > 2) cout << "NIE";
        else cout << string("PA").substr(0, n);
        return;
    }
    if (k == 2) {
        if (n > 4) cout << "NIE";
        else cout << string("PPAA").substr(0, n);
        return;
    }
    if (k == 3) {
        if (n > 8) cout << "NIE";
        else cout << string("PPPAPAAA").substr(0, n);
        return;
    }
    const string cyl = "AAPAPP";
    int rest = n - k;
    if (rest > 0) {
        int cycles = rest / cyl.length();
        for (int i = 0; i < cycles; ++i) word += cyl;
        int left = rest % cyl.length();
        word += cyl.substr(0, left);
    }

    cout << word;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        solution(n,k);
        cout<<endl;
    }
    return 0;
}