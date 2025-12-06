#include <bits/stdc++.h>
using namespace std;

void solution(int n, vector<int> colors) {
    set<int> uniq_colors;

    for (int i=0; i<n; i++) {
        uniq_colors.insert(colors[i]);
    }

    int num_uniq = uniq_colors.size();

    while (uniq_colors.count(num_uniq) == 0) {
        num_uniq++;
    }

    cout << num_uniq << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> colors(n);
        for (int i = 0; i < n; i++) {
            cin >> colors[i];
        }
        solution(n, colors);
    }
}