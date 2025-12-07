#include <bits/stdc++.h>
using namespace std;

void solution(int n, int k, int t, string s) {
    vector<int> p1(n + 1, 0);
    vector<int> p2(n + 1, 0);
    vector<int> p3(n + 1, 0);

    for (int i = 0; i < n; i++) {
        p1[i+1] = p1[i] + (s[i] == '1');
        p2[i+1] = p2[i] + (s[i] == '2');
        p3[i+1] = p3[i] + (s[i] == '3');
    }

    int max_zad = -1;

    int jedynki_caly_dzien = p1[n];
    int dwojki_caly_dzien  = p2[n];
    int trojki_caly_dzien  = p3[n];

    if (jedynki_caly_dzien <= k) {
        int res = trojki_caly_dzien + jedynki_caly_dzien;

        int zapas_k = k - jedynki_caly_dzien;
        res += min(dwojki_caly_dzien, zapas_k);

        max_zad = max(max_zad, res);
    }

    for (int start = 0; start <= n - 2 * t; start++) {

        int rano_1 = p1[start] - p1[0];
        int rano_2 = p2[start] - p2[0];
        int rano_3 = p3[start] - p3[0];

        int auto_tam_1 = p1[start + t] - p1[start];
        int auto_tam_2 = p2[start + t] - p2[start];

        for (int end = start + 2 * t - 1; end < n; end++) {
            int auto_wroc_1 = p1[end + 1] - p1[end - t + 1];
            int auto_wroc_2 = p2[end + 1] - p2[end - t + 1];

            int wieczor_1 = p1[n] - p1[end + 1];
            int wieczor_2 = p2[n] - p2[end + 1];
            int wieczor_3 = p3[n] - p3[end + 1];

            int koszt_obowiazkowy = (rano_1 + wieczor_1) + (auto_tam_1 + auto_tam_2) + (auto_wroc_1 + auto_wroc_2);

            if (koszt_obowiazkowy > k) continue;
            int zysk_bazowy = (rano_3 + wieczor_3) + (rano_1 + wieczor_1);
            int dostepne_dwojki = rano_2 + wieczor_2;
            int pozostale_k = k - koszt_obowiazkowy;

            int zysk_extra = min(dostepne_dwojki, pozostale_k);

            max_zad = max(max_zad, zysk_bazowy + zysk_extra);
        }
    }

    cout << max_zad << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,t;
    cin>>n>>k>>t;
    string resp;
    cin>>resp;
    solution(n, k, t, resp);

    return 0;
}