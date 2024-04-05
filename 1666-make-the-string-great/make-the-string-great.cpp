class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(auto i : s){
            if(!st.empty() && tolower(st.top())==tolower(i)){
                // case not ssaame ie. bad
                if(st.top()!=i){
                    st.pop();
                }else{
                    st.push(i);
                }
            }
            else{
                st.push(i);
            }
        }
        string ans = "";

        while(!st.empty()){
            ans = st.top()+ans;
            st.pop();
        }
        return ans;
    }
};