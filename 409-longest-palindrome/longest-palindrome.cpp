class Solution {

public:
    int longestPalindrome(string s) {
        int maxi = 0;
        unordered_map<char, int> mp;
        for (int i = 0; i < s.length(); i++) {
            if(mp.find(s[i])!=mp.end()){
                mp.erase(s[i]);
                maxi+=2;
            }else{
                mp[s[i]]++;
            }
        }



        

        if( mp.size()>0){
            return maxi+1;
        }

        return maxi;
    }
};