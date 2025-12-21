#include <bits/stdc++.h>
using namespace std;

void solution(int n) {
    vector<int> even;
    vector<int> threes;
    vector<int> fiths;
    vector<int> rest;

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) even.push_back(i);
        else if(i % 3 == 0) threes.push_back(i);
        else if(i % 5 == 0) fiths.push_back(i);
        else rest.push_back(i);
    }

    while(even.size() >= 2 && rest.size() >= 1) {
        cout << rest.back() << " " << even.back() << " ";
        rest.pop_back();
        even.pop_back();
        cout << even.back() << " ";
        even.pop_back();
    }
    while(threes.size() >= 2 && rest.size() >= 1) {
        cout << rest.back() << " " << threes.back() << " ";
        rest.pop_back();
        threes.pop_back();
        cout << threes.back() << " ";
        threes.pop_back();
    }
    while(fiths.size() >= 2 && rest.size() >= 1) {
        cout << rest.back() << " " << fiths.back() << " ";
        rest.pop_back();
        fiths.pop_back();
        cout << fiths.back() << " ";
        fiths.pop_back();
    }

    while(rest.size()) {
        cout << rest.back() << " ";
        rest.pop_back();
    }
    while(even.size()) {
        cout << even.back() << " ";
        even.pop_back();
    }
    while(threes.size()) {
        cout << threes.back() << " ";
        threes.pop_back();
    }
    while(fiths.size()) {
        cout << fiths.back() << " ";
        fiths.pop_back();
    }

    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        solution(n);
    }
    return 0;
}