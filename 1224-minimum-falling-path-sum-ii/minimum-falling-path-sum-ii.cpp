class Solution {

    int getMin(vector<vector<int>>& grid , int row , int col){
        int mini = INT_MAX;
        for(int i = 0 ; i < grid.size();i++){
            if(i!=col){
                mini = min(mini,grid[row][i]);
            }
        }
        return mini;
    }

public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==1){
            return grid[0][0];
        }
        // vector<vector<int>> dp(n,vector<int>(n,0));

        // for(int i= 0 ; i<n ; i++){
        //     dp[n-1][i] = grid[n-1][i];
        // }
        // return  dp[n-1][0];

        for(int i = n-2 ; i >= 0;i--){
            for(int j = n-1 ; j >=0 ; j--){
                int mini = getMin(grid , i+1 , j);
                grid[i][j] = mini+grid[i][j];
            }
        }

        int mini = INT_MAX;
        for(int i = 0 ; i < n;i++){
            mini = min(mini,grid[0][i]);
        }
        return mini;
    }
};