class Solution {
    void bk(vector<int> &nums , vector<vector<int>> &ans , vector<int> &s , vector<bool> &used){
        if(s.size()==nums.size()){
            ans.push_back(s);
            return;
        }

        for(int i = 0 ; i < nums.size();i++){
            if(used[i] || (i>0 && nums[i]==nums[i-1] && !used[i-1])) continue;

            used[i] = true;
            s.push_back(nums[i]);
            bk(nums,ans,s,used);
            s.pop_back();
            used[i] = false;

        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> s;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        bk(nums,ans,s,used);

        return ans;
    }
};