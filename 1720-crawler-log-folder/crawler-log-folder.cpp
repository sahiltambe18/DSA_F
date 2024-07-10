class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<int> st;
        for(auto i : logs){
            if(i=="../"){
                if(!st.empty()) st.pop();

            }else if(i!="./"){
                st.push(1);
            }
        }
        return st.size();
    }
};