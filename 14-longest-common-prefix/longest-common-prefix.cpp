class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // string ans= "";
        unordered_map<string , int> mp;
        int n = strs.size();
        for(int i = 0 ; i < n-1 ; i++){
            string str = strs[i];
            int l = str.length();
            while(l>0){
                mp[str.substr(0,l)]++;
                l--;
            }
        }
        int l = strs[n-1].length();
        while(l>0){
            mp[strs[n-1].substr(0,l)]++;
            if(mp[strs[n-1].substr(0,l)]==n){
                return strs[n-1].substr(0,l);
            }
            l--;
        }
        return "";
    }
};