class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for(char c:s){
            if(!st.empty()){
                if(st.top()=='A' && c=='B'){
                    st.pop();
                }else if(st.top()=='C' && c=='D'){
                    st.pop();
                }else{
                    st.push(c);
                }
            }else{
                st.push(c);
            }
        }
        return st.size();
    }
};