#include <bits/stdc++.h>
using namespace std;

void solution(string s, string t) {
  map<char, int> map_a;
  map<char, int> map_b;

  for (char a : s) {
    map_a[a]++;
  }
  for (char b : t) {
    map_b[b]++;
  }

  bool ifimpossible = true;
  for (auto const& [litera, ilosc] : map_a) {
    if (map_b[litera] < ilosc) {
      ifimpossible = false;
      break;
    }
  }

  if (!ifimpossible) {
    cout<<"Impossible"<<endl;
    return;
  }

  string over = "";
  for (char c = 'a'; c <= 'z'; c++) {
    int diff = map_b[c] - map_a[c];
    for (int i = 0; i < diff; i++) {
      over += c;
    }
  }

  vector<char> next_diff(s.size());
  char last = '{';

  for (int i = s.size() - 1; i >= 0; i--) {
    next_diff[i] = last;
    if (i > 0 && s[i] != s[i-1]) {
      last = s[i];
    }
  }

  string res = "";
  int j = 0;

  for (int i = 0; i < s.size(); i++) {
    char z_char = s[i];

    while (j < over.size() && over[j] < z_char) {
      res += over[j];
      j++;
    }

    while (j < over.size() && over[j] == z_char) {
      if (next_diff[i] > z_char) {
        res += over[j];
        j++;
      } else {
        break;
      }
    }
    res += z_char;
  }
  while (j < over.size()) {
    res += over[j];
    j++;
  }

  cout << res << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
      string s,t;
      cin >> s >> t;
      solution(s,t);
    }

    return 0;
}