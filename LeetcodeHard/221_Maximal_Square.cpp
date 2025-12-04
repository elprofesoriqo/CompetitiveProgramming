class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();
        

        vector<int> left(cols, 0);
        vector<int> right(cols, cols); 
        vector<int> height(cols, 0);

        int maxArea = 0;

        for (int i = 0; i < rows; i++) {
            int current_left = 0;
            int current_right = cols;

            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    height[j]++;

                    left[j] = max(left[j], current_left);
                } else {
                    height[j] = 0;

                    left[j] = 0; 
                    current_left = j + 1;
                }
            }

            for (int j = cols - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') {
                    right[j] = min(right[j], current_right);
                } else {
                    right[j] = cols;
                    current_right = j;
                }
            }

            for (int j = 0; j < cols; j++) {
                int w = right[j] - left[j];
                int h = height[j];
                if(w>=h){
                    maxArea = max(maxArea, h*h);
                }else{
                    maxArea = max(maxArea, w*w);
                }
            }
        }

        return maxArea;
    }
};