#include <bits/stdc++.h>
using namespace std;

vector<int> childrens;

void solution(int n, int k, string s) {
    int il = 0;
    vector<int> stack;
    for (int i = 0; i < n; i++) {
        if(s[i]=='1') {
            stack.clear();
            stack.push_back(i);
        }
        else if(s[i]=='0') {
            if(stack.size() == 0 || stack.size()>=k+1) {
                il+=1;
            }else{
                stack.push_back(s[i]);
            }
        }
    }

    cout<<il<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        solution(n,k,s);

    }

}