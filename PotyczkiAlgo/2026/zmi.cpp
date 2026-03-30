#include <iostream>
using namespace std;

void solution(int x, int d, int h, int m) {
  int koniec = 0;
  if (x == 1) koniec = 24;
  if (x == 2) koniec = 25;
  if (x == 3) koniec = 26;
  if (x == 4) koniec = 27;
  if (x == 5) koniec = 29;

  int mint = (23 - h) * 60 + 60 - m;
  if (d != koniec){
    int dni = koniec - d - 1;
    if (dni > 0) mint += dni * 24 * 60;
    mint += 24 * 60;
  }

  if (x == 5 && (d < 29 || (d == 29 && h < 2))) mint -= 60;

  cout << mint << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int x, d, h, m;
  cin >> x >> d >> h >> m;
  solution(x, d, h, m);

  return 0;
}