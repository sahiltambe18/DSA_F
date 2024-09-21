class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int n = s.length();
        if(n==1) return s;

        for(int i = 0 ; i < n-1 ; i++){
            // odd
            int l = i , r = i;
            while(l>=0 && r < n && s[l]==s[r]){
                l--,r++;
            }
            if(r-l-1 > ans.length()){
                ans = s.substr(l+1,r-l-1);
            }

            if(s[i]==s[i+1]){
                l = i , r = i+1;
                while(l>=0 && r < n && s[l]==s[r]){
                    l--,r++;
                }
                if(r-l-1 > ans.length()){
                    ans = s.substr(l+1,r-l-1);
                }

            }
        }
        return ans;
    }
};