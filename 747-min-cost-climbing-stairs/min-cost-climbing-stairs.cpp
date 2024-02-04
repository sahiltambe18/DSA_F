class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+2,0);
        for( int i = cost.size()-1 ; i >=0 ; i--){
            dp[i] = cost[i] + min(dp[i+1],dp[i+2]);
        }
        return min(dp[0],dp[1]);
    }
};

// [ 1 , 100 , 1 , 1 , 1 , 100 , 1 , 1 , 100 , 1 ]
// [ 6 , 105 , 5 , 5 , 4 , 102 , 3 , 2 , 100 , 1 , 0 , 0 ] from n-1 to 0