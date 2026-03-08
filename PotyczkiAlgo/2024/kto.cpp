#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 18;
    vector<int> algosia(12, 0);
    vector<int> bajtek(12, 0);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        algosia[0] += x;
        algosia[11 - x]++;
    }

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        bajtek[0] += x;
        bajtek[11 - x]++;
    }

    if (algosia > bajtek) cout << "Algosia";
    else if (bajtek > algosia) cout << "Bajtek";
    else cout << "remis";


    return 0;
}