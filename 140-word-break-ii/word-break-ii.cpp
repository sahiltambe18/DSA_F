class Solution {
    vector<string> ans;
    void solve(  string s , unordered_map<string,int> &mp , string curr , int idx){
        if(idx>=s.length()){
            curr.pop_back();
            ans.push_back(curr);
            return;
        }

        for(int i = idx ; i <s.length() ; i++){
            if(mp[s.substr(idx , i-idx+1)]>0){
                string str = s.substr(idx, i-idx+1);
                // mp[str]--;
                solve(s , mp , curr+str+" ", i+1);
                // mp[str]++;
            }
        }

    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> mp;
        for(auto i : wordDict){
            mp[i]++;
        }

        solve(s , mp , "", 0);
        return ans;
    }
};