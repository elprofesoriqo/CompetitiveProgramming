#include <bits/stdc++.h>
using namespace std;

void solution(int n, vector<int> coins) {
    vector<int> even;
    vector<int> odd;
    for (int x : coins) {
        if (x % 2 == 0) even.push_back(x);
        else odd.push_back(x);
    }

    sort(even.rbegin(), even.rend());
    sort(odd.rbegin(), odd.rend());

    vector<long long> prefEven(even.size() + 1, 0);
    for (int i = 0; i < even.size(); i++) {
        prefEven[i + 1] = prefEven[i] + even[i];
    }

    for (int k = 1; k <= n; k++) {
        if (odd.empty()) {
            cout << "0 ";
            continue;
        }
        int take_evens = min((int)even.size(), k - 1);

        int empty_slots = (k - 1) - take_evens;

        if (empty_slots % 2 != 0) {
            take_evens--;
        }
        int needed_trash_odds = (k - 1) - take_evens;

        if (take_evens >= 0 && needed_trash_odds <= (int)odd.size() - 1) {
            cout << odd[0] + prefEven[take_evens] << " ";
        } else {
            cout << "0 ";
        }
    }
    cout << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> coins(n);
        for(int i=0;i<n;i++) cin>>coins[i];
        solution(n, coins);
    }
    return 0;
}