class Solution {
    
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long ans = 0;
        int n = arr.size();
        int mod = 1000000007;
        stack<int> st;
        for(int i = 0 ; i <= n ; i++){
            while(!st.empty() && (i==n || arr[st.top()] >= arr[i])){
                int mid = st.top();
                st.pop();
                
                int l = st.empty() ? -1 : st.top();
                int r = i;

                long count = (mid-l)*(r-mid)%mod;
                ans+= (count*arr[mid])%mod;
                ans%=mod;
            }
            st.push(i);
        }
        return ans;
    }
};