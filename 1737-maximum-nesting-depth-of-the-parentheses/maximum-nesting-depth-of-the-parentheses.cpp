class Solution {
public:
    int maxDepth(string s) {
        int mx = 0;
        stack<char> st;
        for(auto i : s){
            if(i=='('){
                st.push(i);
                if(st.size()>mx){
                    mx = st.size();
                }
            }else if (i==')'){
                st.pop();
            }
        }
        return mx;
    }
};