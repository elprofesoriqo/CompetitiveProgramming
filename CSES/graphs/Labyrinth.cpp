#include <bits/stdc++.h>
using namespace std;

void bfs(int startI, int startJ, int n, int m, vector<vector<char>>& grid) {
    queue<pair<int, int>> q;
    q.push({startI, startJ});


    vector<vector<char>> from(n, vector<char>(m, 0));
    from[startI][startJ] = 'S';

    int endI = -1, endJ = -1;

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        int i = curr.first;
        int j = curr.second;

        if (grid[i][j] == 'B') {
            endI = i;
            endJ = j;
            break;
        }

        if (i - 1 >= 0) {
            if (grid[i-1][j] != '#' && from[i-1][j] == 0) {
                from[i-1][j] = 'U';
                q.push({i-1, j});
            }
        }

        if (i + 1 < n) {
            if (grid[i+1][j] != '#' && from[i+1][j] == 0) {
                from[i+1][j] = 'D';
                q.push({i+1, j});
            }
        }

        if (j - 1 >= 0) {
            if (grid[i][j-1] != '#' && from[i][j-1] == 0) {
                from[i][j-1] = 'L';
                q.push({i, j-1});
            }
        }

        if (j + 1 < m) {
            if (grid[i][j+1] != '#' && from[i][j+1] == 0) {
                from[i][j+1] = 'R';
                q.push({i, j+1});
            }
        }
    }

    if (endI != -1) {
        cout << "YES" << endl;
        string path = "";

        while (endI != startI || endJ != startJ) {
            char move = from[endI][endJ];
            path += move;

            if (move == 'U') endI++;
            else if (move == 'D') endI--;
            else if (move == 'L') endJ++;
            else if (move == 'R') endJ--;
        }

        reverse(path.begin(), path.end());
        cout << path.length() << endl;
        cout << path << endl;
    } else {
        cout << "NO" << endl;
    }
}

void solution(int n, int m, vector<vector<char>>& grid) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                bfs(i, j, n, m, grid);
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    vector<vector<char>>grid(n,vector<char>(m));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) cin>>grid[i][j];
    }
    solution(n,m, grid);
    return 0;
}