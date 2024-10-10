class Solution {

public:
    int coinChange(vector<int>& coins, int amt) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amt+1 , amt+1));
        
        for(int i = 0 ; i <= amt ; i++){
            if(i%coins[0]==0){
                dp[0][i] = i/coins[0];
            }
        }

        for(int i =  1 ; i < n ; i++){
            dp[i][0] = 0;
            for(int j = 1 ; j <=amt ;j++){
                dp[i][j] = dp[i-1][j];
                if(j>=coins[i]){
                    dp[i][j] = min(dp[i][j] , 1+ dp[i][j-coins[i]]);
                }
            }
        }


        return dp[n-1][amt]>amt? -1 : dp[n-1][amt];
        
    }
};