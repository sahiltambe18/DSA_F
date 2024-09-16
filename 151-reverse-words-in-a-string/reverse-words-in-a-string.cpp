class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        int n = s.length();
        string ans ="";
        while(i<n && s[i]==' ') i++;
        while(i<n){
            if(s[i]!=' '){
                int j = i;
                while(j<n && s[j]!=' ') j++;
                ans =" " + s.substr(i, j-i)+ans;
                // ans+=" ";
                i = j;
            }else{
                i++;
            }
        }
        if(ans.empty()) return ans;
        return ans.substr(1);
    }
};