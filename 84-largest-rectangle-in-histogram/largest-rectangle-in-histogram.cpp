class Solution {
    vector<int> nxtSmaller(vector<int> &h ){
        int n = h.size();
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);
        for(int i = n-1 ; i>=0 ;i--){
            while(st.top()!=-1 && h[st.top()]>=h[i]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevSmaller(vector<int> &h){
        int n = h.size();
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);
        for(int i = 0 ; i <n ;i++){
            while(st.top()!=-1 && h[st.top()]>=h[i]) st.pop();
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& h) {
        vector<int> prev , nxt;
        nxt = nxtSmaller(h);
        prev = prevSmaller(h);
        int mx = 0 , n = h.size();
        for(int i = 0 ; i < n ; i++){
            if(nxt[i]==-1){
                nxt[i] = n;
            }
            int area = h[i]*(nxt[i]-prev[i]-1);
            mx = max(mx,area);
        }
        return mx;
    }
};