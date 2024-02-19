class Solution {
    int maxC(unordered_map<char,int> &mp){
        int mx = 0;
        for(auto i : mp){
            if(i.second>mx){
                mx = i.second;
            }
        }
        return mx;
    }
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int ml = 0;
        unordered_map<char,int> mp;
        int start = 0;
        for(int i = 0 ; i < n ;i++){
            mp[s[i]]++;
            int len = i-start+1;
            if(k>=len-maxC(mp)){
                ml = max(ml,len);
            }else{
                if(mp[s[start]]==1){
                    mp.erase(s[start]);
                }else{
                    mp[s[start]]--;
                }
                    start++;
            }
        }
        return ml;
    }
};