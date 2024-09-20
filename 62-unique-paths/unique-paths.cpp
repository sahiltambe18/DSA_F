class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n,1);
        for(int i = 1 ; i<m ; i++){
            vector<int> t(n,1);
            for(int j = 1; j <n ; j++){
                t[j] = dp[j]+t[j-1];
            }
            dp = t;
        }
        return dp[n-1];
    }
};