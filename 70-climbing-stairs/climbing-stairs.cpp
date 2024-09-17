class Solution {
public:
    int climbStairs(int n) {
        int dp[46];
        dp[0] = 1;
        dp[1] = 1;
        // dp[2] = 2;
        // dp[3] = 3;

        for(int i = 2 ; i<=n ; i++){
            dp[i] = dp[i-1]+dp[i-2];
        }

        return dp[n];
    }   
};
/*
0   1   2   3   4   5   6   7   8   9
0   1   2   3   3   4   4
*/