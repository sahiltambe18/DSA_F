class Solution {
    bool check(string str){
        stack<char> st;
        for(auto i : str){
            if(i=='('){
                st.push(i);
            }else{
                if(st.empty()){
                    return 0;
                }
                else if(i==')'){
                    st.pop();
                }else{
                    return false;
                }
            }
        }
        return st.empty();
    }
    void helper(vector<string> &ans , int n , string str){
        if(2*n==str.length()){
            if(check(str)){
                ans.push_back(str);
            }
            return;
        }

        helper(ans, n , str+"(");
        helper(ans,n,str+")");
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(ans , n,"");
        return ans;
    }
};