class Solution {
    void bk(vector<vector<int>> &ans, vector<int>& curr, vector<int>& nums , int idx){
        if(idx==nums.size()){
            ans.push_back(curr);
            return;
        }
        bk(ans , curr , nums , idx+1);
        curr.push_back(nums[idx]);
        bk(ans , curr , nums , idx+1);
        curr.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        bk(ans,curr,nums,0);
        return ans;
    }
};