#include <iostream>
using namespace std;

const int MAX_SIZE = 1000;

void generujWzor(char wzor[MAX_SIZE][MAX_SIZE], int n, int x, int y, int rozmiar, int poziom) {
    if (poziom == 1) {
        for (int i = 0; i < rozmiar; i++) {
            for (int j = 0; j < rozmiar; j++) {
                if (i %2==1 || j%2==1) {
                    wzor[x + i][y + j] = '#';
                } else {
                    wzor[x + i][y + j] = ' ';
                }
            }
        }
        return;
    }

    int mniejszyRozmiar = rozmiar / n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i%2==1 || j%2==1) {
                generujWzor(wzor, n, x + i * mniejszyRozmiar, y + j * mniejszyRozmiar, mniejszyRozmiar, poziom - 1);
            }
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    int rozmiar = 1;
    for (int i = 0; i < k; ++i) {
        rozmiar *= n;
    }

    char wzor[MAX_SIZE][MAX_SIZE] = { ' ' };

    generujWzor(wzor, n, 0, 0, rozmiar, k);

    for (int i = 0; i < rozmiar; ++i) {
        for (int j = 0; j < rozmiar; ++j) {
            cout << wzor[i][j];
        }
        cout << endl;
    }

    return 0;
}
