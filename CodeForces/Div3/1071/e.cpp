#include <bits/stdc++.h>
using namespace std;

void solution(int n, long long x, long long y, string s, vector<long long>&p) {
    long long total_points = 0;
    for (int i = 0; i < n; i++) {
        total_points += p[i];
    }

    if (total_points > x + y) {
        cout << "NO" << endl;
        return;
    }

    long long spare_moves = (x + y) - total_points;

    long long lower_bound = 0;
    long long upper_bound = 0;
    vector<long long> even_a_list;
    vector<long long> even_b_list;
    bool has_a_wins = false;
    bool has_b_wins = false;

    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            has_a_wins = true;
            lower_bound += (p[i] / 2) + 1;
            upper_bound += p[i];
            if (p[i] % 2 == 0) {
                even_a_list.push_back(p[i]);
            }
        } else {
            has_b_wins = true;
            upper_bound += (p[i] - 1) / 2;
            if (p[i] % 2 == 0) {
                even_b_list.push_back(p[i]);
            }
        }
    }

    long long minimum_score = lower_bound;
    if (!has_b_wins) {
        long long moves_left = spare_moves;
        if (moves_left <= (long long)even_a_list.size()) {
        } else {
            moves_left -= even_a_list.size();
            minimum_score += (moves_left + 1) / 2;
        }
    }

    long long maximum_score = upper_bound;
    if (has_a_wins) {
        maximum_score += spare_moves;
    } else {
        long long moves_left = spare_moves;
        long long beneficial = min(moves_left, (long long)even_b_list.size());
        maximum_score += beneficial;
        moves_left -= beneficial;
        maximum_score += moves_left / 2;
    }

    bool is_valid = (x >= minimum_score && x <= maximum_score);
    cout << (is_valid ? "YES" : "NO") << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long x, y;
        cin >> n >> x >> y;
        string s;
        cin >> s;
        vector<long long> p(n);
        for (int i = 0; i < n; i++) cin >> p[i];
        solution(n, x, y, s, p);
    }
    return 0;
}