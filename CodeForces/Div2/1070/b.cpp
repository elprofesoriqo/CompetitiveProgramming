#include <bits/stdc++.h>
using namespace std;

void solution(int n, string bin) {
    int front = 0;
    while (front < n && bin[front] == '0') {
        front++;
    }
    if (front == n) {
        cout << n << endl;
        return;
    }

    int back = 0;
    while (back < n && bin[n - 1 - back] == '0') {
        back++;
    }

    int max_mid = 0;
    int current_streak = 0;
    for (int i = 0; i < n; i++) {
        if (bin[i] == '0') {
            current_streak++;
        } else {
            max_mid = max(max_mid, current_streak);
            current_streak = 0;
        }
    }

    max_mid = max(max_mid, current_streak);
    int result = max(max_mid, front + back);

    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        string bin;
        cin>>bin;
        solution(n, bin);
    }
    return 0;
}