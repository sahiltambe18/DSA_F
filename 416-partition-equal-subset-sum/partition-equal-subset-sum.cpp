class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2) return 0;
        sum/=2;
        vector<vector<int>> dp(n,vector<int>(sum+1,0));
        dp[0][0] = 1;
        if(nums[0]<=sum) dp[0][nums[0]] = 1;
        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j<=sum ; j++){
                // not take
                dp[i][j] = dp[i-1][j];
                if(j-nums[i]>=0 && dp[i-1][j-nums[i]]){
                    dp[i][j] = dp[i-1][j-nums[i]];
                }
            }
        }
        return dp[n-1][sum];
    }
};