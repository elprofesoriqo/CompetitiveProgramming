class Solution {
public:
    int m, n;
    vector<vector<int>> memo; 
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
    
        memo = vector<vector<int>>(m, vector<int>(n, 0));

        int max_len = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int len = dfs(matrix, i, j);
                max_len = max(max_len, len);
            }
        }

        return max_len;
    }

    int dfs(vector<vector<int>>& matrix, int i, int j) {
        if (memo[i][j] != 0) {
            return memo[i][j];
        }

        int maxLen = 1;

        for (auto& d : directions) {
            int x = i + d[0];
            int y = j + d[1];

            if (x >= 0 && x < m && y >= 0 && y < n) {
                if (matrix[x][y] > matrix[i][j]) {
                    int len = 1 + dfs(matrix, x, y);
                    maxLen = max(maxLen, len);
                }
            }
        }
        
        memo[i][j] = maxLen;
        return maxLen;
    }
};