#include <bits/stdc++.h>
using namespace std;

int get_ctz(long long n) {
    if (n == 0) return 64;
    return countr_zero((unsigned long long)n);
}

int get_trailing_ones(long long n) {
    return countr_zero(~(unsigned long long)n);
}

void solution(long long l, long long r) {
    if (l == r) {
        cout << 0 << "\n";
        return;
    }

    int zeros_l = get_ctz(l);
    int ones_r = get_trailing_ones(r);

    int max_x = min(zeros_l, ones_r);
    // x < 2^k
    long long res = (1LL << max_x) - 1;

    int diffrence_msb = bit_width((unsigned long long)(l ^ r)) - 1;

    if (diffrence_msb >= max_x) {
        long long pivot = 1LL << diffrence_msb;
        long long len_l = pivot - (l & (pivot - 1));
        long long len_r = (r & (pivot - 1)) + 1;

        if (len_l == len_r) res += (1LL << countr_zero((unsigned long long)len_l));
    }

    cout << res << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        long long l,r;
        cin >> l >> r;
        solution(l,r);
    }
    return 0;
}