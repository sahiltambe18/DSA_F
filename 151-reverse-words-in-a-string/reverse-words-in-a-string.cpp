class Solution {
public:
    string reverseWords(string s) {
        int r = s.size()-1;
        int endInd = r;
        string ans="";

        while(0<=r){
            while(r>=0 && s[r] == ' ')  r--;
            if(r<0)   break;
            endInd = r;
            
            while(r>=0 && s[r] != ' '){
                r--;
            }
            ans += s.substr(r+1,endInd-r);
            ans.push_back(' ');
        }
        ans.pop_back();
        return ans;
    }
};