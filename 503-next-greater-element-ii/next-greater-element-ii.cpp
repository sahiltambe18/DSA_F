class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans , nge;
        stack<int> st;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            int maxi = -1;
            for(int j = (i+1)%n ; j != i ; j = (j+1)%n){
                if(nums[i]<nums[j]){
                    maxi = nums[j];
                    break;
                }
            }
            ans.push_back(maxi);
        }
        return ans;

    }
};