class Solution {
public:
    string makeGood(string s) {
        // stack<char> st;
        string ans = "";
        for(auto i : s){
            if(!ans.empty() && tolower(ans.back())==tolower(i)){
                // case not ssaame ie. bad
                if(ans.back()!=i){
                    // st.pop();
                    ans.pop_back();
                }else{
                    ans.push_back(i);
                }
            }
            else{
                ans.push_back(i);
            }
        }

        // while(!st.empty()){
        //     ans = st.top()+ans;
        //     st.pop();
        // }
        return ans;
    }
};