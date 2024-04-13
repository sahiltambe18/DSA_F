class Solution {
    int mx = 0;
    int solve(vector<vector<char>>& matrix, int x, int j,
              vector<vector<int>>& dp) {
        if (x >= matrix.size() || j >= matrix[0].size()) {
            return 0;
        }
        if (dp[x][j] != -1)
            return dp[x][j];
        int right = solve(matrix, x, j + 1, dp);
        int diagonal = solve(matrix, x + 1, j + 1, dp);
        int down = solve(matrix, x + 1, j, dp);
        if (matrix[x][j] == '1') {
            int ans = 1 + min(min(right, diagonal), down);
            mx = max(mx, ans);
            dp[x][j] = ans;
            return ans;
        } else {
            dp[x][j] = 0;
            return 0;
        }
    }

public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int x = n - 1; x >= 0; x--) {
            for (int j = m - 1; j >= 0; j--) {

                
                int right = dp[x][j+1];
                int diagonal = dp[x+1][j+1];
                int down = dp[x+1][j];

                if (matrix[x][j] == '1') {
                    dp[x][j] = 1 + min(min(right, diagonal), down);
                    mx = max(mx,dp[x][j]);
                } else {
                    dp[x][j] = 0;
                }
            }
        }
        //solve(matrix, 0, 0, dp);
        return mx*mx;
    }
};