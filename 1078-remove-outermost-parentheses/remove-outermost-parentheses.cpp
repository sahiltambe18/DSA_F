class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int opened = 0;
        for(auto i : s){
            if(i=='('){
                if(opened>0){
                    ans+=i;
                }
                opened++;
            }else{
                if(opened>1){
                    ans+=i;
                }
                opened--;
            }
        }
        return ans;
    }
};