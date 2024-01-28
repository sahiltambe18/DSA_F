class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return {-1};
        
        vector<int>ans(n,-1);
        stack<int>st;
        for(int i=(2*n)-1; i>=0; i--)
        {
            int ele = nums[i%n];
            while(!st.empty() && st.top()<=ele)
                st.pop();
            
            if(st.empty())
                ans[i%n] = -1;
            else
                ans[i%n] = st.top();
            st.push(ele);
        }
        return ans;
    }
};