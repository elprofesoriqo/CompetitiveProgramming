#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int n, int* arr) {
    for (int i=1; i < n-1; i++) if(arr[i]==-1) arr[i]=0;

    if (arr[0] == -1 && arr[n-1] == -1) {
        arr[0] = 0;
        arr[n-1] = 0;
    }
    else if (arr[0] == -1) arr[0] = arr[n-1];
    else if (arr[n-1] == -1) arr[n-1] = arr[0];


    int min_diff = abs(arr[n-1] - arr[0]);

    cout << min_diff << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        int* arr = new int[n];

        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        solve(n, arr);
        delete[] arr;
    }

    return 0;
}