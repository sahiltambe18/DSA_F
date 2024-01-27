class Solution {
   
    void helper(vector<string> &ans , int open , int close , string str){
        if(open == 0 && close == 0){
            ans.push_back(str);
            return;
        }

        if(open > 0){
            helper(ans , open-1 , close , str+"(");
        }
        if(close>0 && open<close){
            helper(ans , open , close-1 , str+")");
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(ans ,n, n,"");
        return ans;
    }
};