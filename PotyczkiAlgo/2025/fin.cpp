#include <bits/stdc++.h>
using namespace std;

void solution(int n, vector<pair<int,int>> zawodnicy) {
    vector<int> final;
    for (int i = 0; i < 10; i++) {
        final.push_back(zawodnicy[i].first);
    }

    int left=10;
    for(int i=10; i<zawodnicy.size(); i++) {
        if(!left) break;
        if(zawodnicy[i].second<2) {
            final.push_back(zawodnicy[i].first);
            left--;
        }
    }
    for (int v: final) {
        cout<<v<<" ";
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    vector<pair<int,int>> zawodnicy;
    cin>>n;
    for(int i=1;i<=n;i++) {
        string s;
        int x;
        cin>>s>>x;
        if(s=="TAK") {
            zawodnicy.push_back({i,x});
        }
    }
    solution(n, zawodnicy);
    return 0;
}