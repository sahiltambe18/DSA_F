class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;

        for(int i = 0 ; i < nums.size() ; i++){

            // remove idx out of window
            while(!dq.empty() && dq.front() < i-k+1){
                dq.pop_front();
            }

            // maintain increasing order
            while(!dq.empty() && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }

            dq.push_back(i);
            // add to ans
            if(i >=k-1){
                ans.push_back(nums[dq.front()]);
            }

        }

        return ans;
    }
};