class Solution {
    int solve(string s , unordered_set<string> &st , int idx , int n , unordered_map<int,int> &dp){
        if(idx>=n) return 0;
        if(dp.find(idx)!=dp.end()) return dp[idx];
        int res = 1 + solve(s , st , idx+1 , n,dp);

        for(int i = idx ; i<n ; i++){
            if(st.count(s.substr(idx,i-idx+1)) >0) {
                // found
                res = min(res , solve(s,st,i+1 , n , dp));
            }
        }

        return dp[idx] = res;

    }
public:
    int minExtraChar(string s, vector<string>& dict) {
        unordered_set<string> st(begin(dict) , end(dict));
        unordered_map<int,int> dp;
        int n = s.length();
        return solve(s,st , 0 , n , dp);

    }
};