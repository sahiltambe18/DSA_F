class Solution {
public:
    int largestRectangleArea(vector<int>&  h) {
        int i = 0 , n = h.size();
        int mx = INT_MIN;
        stack<int> st;
        while(i<n){
            while(!st.empty() && h[st.top()]>= h[i]){
                int idx = st.top();
                st.pop();
                if(st.empty()){
                    mx = max(mx , h[idx]*i);
                }else{
                    mx = max(mx , h[idx]*(i-st.top()-1));
                }
            }
            st.push(i);
            i++;
        }

        while(!st.empty()){
            int idx = st.top();
            st.pop();
            if(st.empty()){
                mx = max(mx , h[idx]*i);
            }else{
                mx = max(mx , h[idx]*(i-st.top()-1));
            }
        }
        return mx;
    }
};