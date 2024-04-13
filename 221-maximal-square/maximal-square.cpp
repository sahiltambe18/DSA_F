class Solution {

public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int mx = 0;

        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        vector<int> curr(m + 1, 0), next(m + 1, 0);
        for (int x = n - 1; x >= 0; x--) {
            for (int j = m - 1; j >= 0; j--) {

                int right = curr[j + 1];
                int diagonal = next[j + 1];
                int down = next[j];

                if (matrix[x][j] == '1') {
                    curr[j] = 1 + min(min(right, diagonal), down);
                    mx = max(mx, curr[j]);
                } else {
                    curr[j] = 0;
                }
            }
            next = curr;
        }
        // solve(matrix, 0, 0, dp);
        return mx * mx;
    }
};