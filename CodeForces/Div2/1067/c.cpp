#include <bits/stdc++.h>
using namespace std;

void solve(int n,int k, vector<int> a, vector<int> b) {
    long long mmax = -1e18;
    if(k%2==0) {
        long long cmax = -1e18;
        for (int i=0; i<n; i++) {
            if (cmax < 0) cmax = a[i];
            else cmax += a[i];

            mmax = max(mmax, cmax);
        }
        cout << mmax << endl;
    }else{
        vector<long long> sumpref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            sumpref[i + 1] = sumpref[i] + a[i];
        }

        vector<vector<long long>> sparsetab_min(19, vector<long long>(n + 1));
        vector<vector<long long>> sparsetab_max(19, vector<long long>(n + 1));

        for (int i = 0; i <= n; i++) {
            sparsetab_min[0][i] = sumpref[i];
            sparsetab_max[0][i] = sumpref[i];
        }

        for (int j = 1; j < 19; j++) {
            int fullen = pow(2,j);
            int halflen = pow(2, j-1);

            for (int i = 0; i + fullen <= n + 1; i++) {
                long long sum_l = sparsetab_min[j - 1][i];
                long long sum_r = sparsetab_min[j - 1][i + halflen];

                sparsetab_min[j][i] = min(sum_l, sum_r);
                long long max_l = sparsetab_max[j - 1][i];
                long long max_r = sparsetab_max[j - 1][i + halflen];
                sparsetab_max[j][i] = max(max_l, max_r);
            }
        }

        auto query_min = [&](int L, int R) {
            int len = __lg(R - L + 1);
            return min(sparsetab_min[len][L], sparsetab_min[len][R - (1 << len) + 1]);
        };
        auto query_max = [&](int L, int R) {
            int len = __lg(R - L + 1);
            return max(sparsetab_max[len][L], sparsetab_max[len][R - (1 << len) + 1]);
        };

        vector<int> L_bound(n), R_bound(n);
        vector<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && b[st.back()] <= b[i]) st.pop_back();
            L_bound[i] = st.empty() ? -1 : st.back();
            st.push_back(i);
        }
        st.clear();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && b[st.back()] < b[i]) st.pop_back();
            R_bound[i] = st.empty() ? n : st.back();
            st.push_back(i);
        }

        for (int i = 0; i < n; i++) {
            long long max_sumpref = query_max(i + 1, R_bound[i]);
            long long min_sumpref = query_min(L_bound[i] + 1, i);

            mmax = max(mmax, max_sumpref - min_sumpref + b[i]);
        }
        cout << mmax << endl;


    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> b(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        solve(n,k,a,b);
    }
    return 0;
}