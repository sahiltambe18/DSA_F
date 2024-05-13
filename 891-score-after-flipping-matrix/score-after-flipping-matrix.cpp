class Solution {


public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 0) {
                for (int j = 0; j < m; j++) {
                    if (grid[i][j] == 0) {
                        grid[i][j] = 1;
                    } else {
                        grid[i][j] = 0;
                    }
                }
            }
        }

        for (int j = 0; j < m; j++) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (grid[i][j] == 0) {
                    cnt++;
                }
            }
            if (cnt > n / 2) {
                for (int i = 0; i < n; i++) {
                    if (grid[i][j] == 0) {
                        grid[i][j] = 1;
                    } else {
                        grid[i][j] = 0;
                    }
                }
            }
        }
        int res = 0;
         for (int i=0; i <= n - 1; i++) {
            int num = 0;
            for (int j=0; j <= m - 1; j++) {
                if (grid[i][j]) num |= (1<<(m - j - 1));
            }
            res += num;
        }

        return res;
    }
};