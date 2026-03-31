#include <bits/stdc++.h>
using namespace std;

vector<int> carry_in;
vector<int> carry_out;

long long dc(int l, int r) {
    if (l > r) return 0;
    if (l == r) {
        if (carry_in[l] == 0 && carry_out[l] == 0) return 1;
        return 0;
    }

    int mid = l + (r -l)/2;
    long long pars = dc(l, mid) + dc(mid + 1, r);

    if (carry_in[mid] != -1 && carry_out[mid + 1] != -1 && carry_in[mid] == carry_out[mid + 1]) {
        long long l_start = 0;
        for (int i = mid; i >= l; --i) {
            if (carry_in[i] == -1) break;
            if (i < mid && carry_in[i] != carry_out[i + 1]) break;
            if (carry_out[i] == 0) l_start++;
        }
        long long r_ends = 0;
        for (int j = mid + 1; j <= r; ++j) {
            if (carry_in[j] == -1) break;
            if (j > mid + 1 && carry_out[j] != carry_in[j - 1]) break;
            if (carry_in[j] == 0) r_ends++;
        }

        pars += l_start * r_ends;
    }
    return pars;
}

void solution(const string& a, const string& b, const string& c) {
    int n = a.length();
    carry_in = vector<int>(n, -1);
    carry_out = vector<int>(n, -1);

    for (int k = 0; k < n; ++k) {
        if ((a[k] - '0' + b[k] - '0') % 10 == c[k] - '0') {
            carry_in[k] = 0;
            carry_out[k] = (a[k] - '0' + b[k] - '0') / 10;
        }
        else if ((a[k] - '0' + b[k] - '0' + 1) % 10 == c[k] - '0') {
            carry_in[k] = 1;
            carry_out[k] = (a[k] - '0' + b[k] - '0' + 1) / 10;
        }
    }

    cout << dc(0, n - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string a, b, c;
    cin >> a >> b >> c;

    solution(a, b, c);
    return 0;
}