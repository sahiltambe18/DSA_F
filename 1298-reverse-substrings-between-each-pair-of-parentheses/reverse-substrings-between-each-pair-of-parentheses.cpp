class Solution {
    void rev(string &str , int s , int r){
        while(s<=r){
            char c = str[s];
            str[s] = str[r];
            str[r] = c;
            s++;
            r--;
        }
    }
public:
    string reverseParentheses(string s) {
        stack<int> st;
        for(int r = 0; r < s.size() ; r++){
            if(s[r]=='('){
                st.push(r);
            }else if(s[r]==')'){
                rev(s , st.top() , r);
                st.pop();
            }
        }
        string ans = "";
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i]=='(' || s[i]==')') continue;
            ans+=s[i];
        }
        return ans;
    }
};