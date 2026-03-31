#include <bits/stdc++.h>
using namespace std;

int find_set(int v, vector<int>& parent) {
    int root = v;
    while (root != parent[root]) root = parent[root];
    while (v != root) {
        int next = parent[v];
        parent[v] = root;
        v = next;
    }
    return root;
}

void merge_party(int a, int b, vector<int>& parent, vector<set<int>>& adj, const vector<int>& col, vector<int>& cnt_comp, queue<int>& Q, const vector<bool>& rmvd, vector<map<int, int>>& tchs) {
    a = find_set(a, parent);
    b = find_set(b, parent);
    if (a == b) return;
    if (adj[a].size() < adj[b].size()) swap(a, b);
    parent[b] = a;
    int c = col[a];
    cnt_comp[c]--;

    if (cnt_comp[c] == 1) Q.push(c);
    for (int idx : adj[b]) {
        idx = find_set(idx, parent);
        if (idx == a) continue;
        if (rmvd[col[idx]]) tchs[idx][c] = a;
        adj[a].insert(idx);
    }
    adj[b].clear();
}

void merge_wild(int w1, int w2, vector<int>& parent, vector<set<int>>& adj, const vector<int>& col, vector<int>& cnt_comp, queue<int>& Q, const vector<bool>& rmvd, vector<map<int, int>>& tchs) {
    w1 = find_set(w1, parent);
    w2 = find_set(w2, parent);
    if (w1 == w2) return;
    if (tchs[w1].size() < tchs[w2].size()) swap(w1, w2);

    parent[w2] = w1;

    for (pair<const int, int>& kv : tchs[w2]) {
        int c = kv.first;
        int cmpB = find_set(kv.second, parent);

        if (tchs[w1].count(c)) {
            int cmpA = find_set(tchs[w1][c], parent);
            merge_party(cmpA, cmpB, parent, adj, col, cnt_comp, Q, rmvd, tchs);
            tchs[w1][c] = find_set(cmpA, parent);
        } else {
            tchs[w1][c] = cmpB;
            adj[cmpB].insert(w1);
        }
    }
    tchs[w2].clear();
}


void solution(int n, int m, int k, const vector<int>& col, const vector<pair<int, int>>& e) {
    vector<int> f_col(k + 1, -1);
    for (int i = 1; i <= n; ++i) f_col[col[i]] = i;

    vector<int> parent(n + 1);
    for (int i = 0; i <= n; ++i) parent[i] = i;

    vector<int> cnt_comp(k + 1, 0);
    vector<bool> rmvd(k + 1, false);
    for (int c = 1; c <= k; ++c) if (f_col[c] == -1) rmvd[c] = true;

    vector<set<int>> adj(n + 1);
    vector<map<int, int>> tchs(n + 1);
    for (int i = 1; i <= n; ++i) cnt_comp[col[i]]++;

    for (auto& edge : e) {
        int u = edge.first;
        int v = edge.second;
        if (col[u] == col[v]) {
            int root_u = find_set(u, parent);
            int root_v = find_set(v, parent);
            if (root_u != root_v) {
                parent[root_v] = root_u;
                cnt_comp[col[root_u]]--;
            }
        }
    }

    for (auto& edge : e) {
        int u = edge.first;
        int v = edge.second;
        if (col[u] != col[v]) {
            int root_u = find_set(u, parent);
            int root_v = find_set(v, parent);
            adj[root_u].insert(root_v);
            adj[root_v].insert(root_u);
        }
    }

    queue<int> Q;
    for (int c = 1; c <= k; ++c) if (cnt_comp[c] == 1 && !rmvd[c]) Q.push(c);

    while (!Q.empty()) {
        int c = Q.front();
        Q.pop();
        if (rmvd[c]) continue;
        rmvd[c] = true;
        int jock = find_set(f_col[c], parent);
        vector<int> curr_adj(adj[jock].begin(), adj[jock].end());

        for (int idx : curr_adj) {
            idx= find_set(idx, parent);
            if (idx == jock) continue;

            if (rmvd[col[idx]]) {
                merge_wild(jock, idx, parent, adj, col, cnt_comp, Q, rmvd, tchs);
                jock = find_set(jock, parent);
            } else {
                int cnt = col[idx];
                if (tchs[jock].count(cnt)) {
                    int cmp = find_set(tchs[jock][cnt], parent);
                        merge_party(cmp, idx, parent, adj, col, cnt_comp, Q, rmvd, tchs);
                    tchs[jock][cnt] = find_set(cmp, parent);
                } else {
                    tchs[jock][cnt] = idx;
                    adj[idx].insert(jock);
                }
            }
        }
        adj[jock].clear();
    }

    bool ok = true;
    for (int c = 1; c <= k; ++c) {
        if (!rmvd[c]) {
            ok = false;
            break;
        }
    }

    if (ok) cout << "TAK" << "\n";
    else cout << "NIE"<<"\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> col(n + 1);
        for (int i = 1; i <= n; ++i) cin >> col[i];

        vector<pair<int, int>> e(m);
        for (int i = 0; i < m; ++i) cin >> e[i].first >> e[i].second;
        solution(n, m, k, col, e);
    }
    return 0;
}