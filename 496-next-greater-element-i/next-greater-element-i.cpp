class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& n1, vector<int>& n2) {
        vector<int> ans;
        stack<int> st;
        map<int ,int> mp;
        mp[n2[n2.size()-1]] = -1;
        st.push(n2[n2.size()-1]); 
        for(int i = n2.size()-2 ; i >=0 ; i--){
            if(st.top() > n2[i]){
                mp[n2[i]] = st.top();
                st.push(n2[i]);
            }else if(st.top()<n2[i]){
                while(!st.empty() && st.top()<n2[i]){
                    st.pop();
                }
                if(!st.empty()){
                    mp[n2[i]] = st.top();
                }else{
                    mp[n2[i]] = -1;
                }
                    st.push(n2[i]);
            }
        }
        for(int i : n1){
            ans.push_back(mp[i]);
        }
        return ans;
    }
};