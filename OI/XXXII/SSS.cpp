#include <bits/stdc++.h>
using namespace std;

vector<int> childrens;

void dfs(int u, int p, const vector<vector<int>> &szp) {
    int count = 0;

    for (int v : szp[u]) {
        if (v != p) {
            count++;
            dfs(v, u, szp);
        }
    }

    childrens[u] = count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n, k;
        cin >> n >> k;

        childrens.assign(n + 1, 0);
        vector<vector<int>> szp(n + 1);

        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            szp[a].push_back(b);
            szp[b].push_back(a);
        }

        dfs(1, -1, szp);


        vector<pair<int, int>> nodes;
        for (int i = 1; i <= n; i++) {
            nodes.push_back({childrens[i], i});
        }

        sort(nodes.begin(), nodes.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            if (a.first != b.first) {
                return a.first > b.first;
            }
            return a.second < b.second;
        });

        for (int i = 0; i < k; i++) {
            cout << nodes[i].second << " ";
        }
        cout << "\n";
    }
    return 0;
}