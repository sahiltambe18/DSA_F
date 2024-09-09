class Solution {
public:
    int coinChange(vector<int>& coins, int amt) {
        int n = coins.size();
        vector<int> dp(amt+1 , amt+1);
        dp[0]=0;
        for(int i = 0 ; i < n ; i++){
            for(int j = coins[i] ; j <=amt ; j++ ){
                dp[j] = min(dp[j],dp[j-coins[i]]+1);
            }
        }


        return dp[amt]>amt? amt : dp[amt];
        
    }
    int numSquares(int n) {
        int sq = sqrt(n);
        vector<int> v;
        for(int i = 1 ; i <= sq ; i++) v.push_back(i*i);
        return coinChange(v,n);   
    }
};
/*
    0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20  n
1   0   1   2   3   4   5   6   7   8   9   10
2   0   1   2   3   1   
3   0   1   1   1   2   
4
5
sqrt n

*/ 