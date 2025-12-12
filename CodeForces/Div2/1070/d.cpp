#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353

vector<int> memo;
vector<long long> a;

bool smaller(const pair<int, int>& p1, const pair<int, int>& p2) {
    return a[p1.first] < a[p2.first];
}

int dfs(int edge_index, const vector<vector<pair<int, int>>>& adj, const vector<pair<int, int>>& all_edges) {

    if (memo[edge_index] != -1) {
        return memo[edge_index];
    }

    int u = all_edges[edge_index].first;
    int v = all_edges[edge_index].second;

    long long t = a[u] + a[v];

    long long current_paths = 1;

    int left = 0;
    int right = adj[v].size() - 1;
    int start_index = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int v_mid = adj[v][mid].first;

        if (a[v_mid] >= t) {
            start_index = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    if (start_index != -1) {
        for (int i = start_index; i < adj[v].size(); i++) {
            int next_v = adj[v][i].first;
            int next_edge_idx = adj[v][i].second;

            if (a[next_v] > t) {
                break;
            }

            if (a[next_v] == t) {
                current_paths = (current_paths + dfs(next_edge_idx, adj, all_edges)) % MOD;
            }
        }
    }

    memo[edge_index] = current_paths;
    return current_paths;
}


void solution(int n, int m, vector<vector<pair<int, int>>>& adj, const vector<pair<int, int>>& edges) {
    long long paths = 0;
    memo.assign(m, -1);

    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end(), smaller);
    }

    for (int i = 0; i < m; i++) {
        paths = (paths + dfs(i, adj, edges)) % MOD;
    }

    cout << paths << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        a.assign(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        vector<vector<pair<int, int>>> adj(n + 1);
        vector<pair<int, int>> edges;

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back({v, i});
            edges.push_back({u, v});
        }

        solution(n, m, adj, edges);
    }
    return 0;
}