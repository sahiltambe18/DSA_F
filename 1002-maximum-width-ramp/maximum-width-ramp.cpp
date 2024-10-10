class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int mx = 0; 
        stack<int> st;
        int n = nums.size(); 
        for(int i = 0 ;i< n ; i++){
            if(st.empty() || nums[st.top()]>nums[i]){
                st.push(i);
            }
        }

        for(int i = n-1 ; i >=0 && !st.empty() ; i--){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                if(mx < i-st.top()){
                    mx = i-st.top();
                }
                st.pop();
            }
        }

        return mx;
    }
};