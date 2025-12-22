#include <bits/stdc++.h>
using namespace std;

void add_numbers(vector<int>& numbers, int n) {
    while (n > 0) {
        numbers.push_back(n%10);
        n/=10;
    }
    sort(numbers.begin(), numbers.end());
}

void solution(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for(int i = 1; i <= n; i++) {
        vector<int> numbers;
        add_numbers(numbers, i);

        if(numbers.size()==1) {
            dp[i] = 1;
        }else {
            dp[i] = dp[i-numbers.back()] + 1;
            numbers.pop_back();
        }
    }

    cout << dp[n] << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    solution(n);
    return 0;
}