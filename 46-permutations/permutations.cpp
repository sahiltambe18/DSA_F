class Solution {
    bool allv(vector<bool>& vis){
        for(auto i : vis){
            if(!i){
                return false;
            }
        }
        return true;
    }
    void backtrack(vector<vector<int>> &ans , vector<int>& nums , vector<int>& v , vector<bool>& vis){
        if(allv(vis)){
            ans.push_back(v);
            return ;
        }
        for(int i = 0 ; i < vis.size() ; i++){
            if(!vis[i]){
                v.push_back(nums[i]);
                vis[i] = true;
                backtrack(ans,nums,v,vis);
                vis[i] = false;
                v.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<bool> vis( nums.size() , false);
        vector<int> v;
        backtrack(ans, nums , v , vis);
        return ans;

    }
};