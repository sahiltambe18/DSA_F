
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n+1 , false);
        dp[n]=true;

        for(int i = n-1 ; i >=0 ; i--){
            for(auto j : wordDict){
                int len = j.length(); 
                if(i+len<=n && s.substr(i,len)==j){
                    dp[i] = dp[i+len];
                }
                if(dp[i]) break;
            }
        }
        return dp[0];
    }
};
