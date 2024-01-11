class Solution {
    void subsets(vector<vector<int>> &ans , vector<int> nums, vector<int> v , int i){
        if(i==nums.size()){
            ans.push_back(v);
            return;
        }

        v.push_back(nums[i]);
        subsets(ans , nums , v , i+1);
        v.pop_back();
        subsets(ans , nums , v , i+1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        subsets(ans , nums, v , 0);
        return ans;
    }
};