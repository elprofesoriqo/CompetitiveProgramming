#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int j, int n, int m, vector<vector<char>> &grid){
    if(i==n || j==m || i<0 || j<0) return;

    if(grid[i][j]=='#') return;
    else if(grid[i][j]=='.') grid[i][j]='#';

    dfs(i-1,j,n,m,grid);
    dfs(i+1,j,n,m,grid);
    dfs(i,j-1,n,m,grid);
    dfs(i,j+1,n,m,grid);
}

void solution(int n, int m, vector<vector<char>>& grid) {
    int rooms=0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                dfs(i,j, n, m, grid);
                rooms++;
            }
        }
    }
    cout<<rooms;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cin >> grid[i][j];
    }
    solution(n,m, grid);
    return 0;
}