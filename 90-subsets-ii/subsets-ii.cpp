class Solution {
    void backtrack(vector<int> &nums , vector<int> &v , vector<vector<int>> &ans , int n){
        
        ans.push_back(v);
        if(n==nums.size()){
            return;
        }

        for(int i = n ; i < nums.size() ; i++){
            if(i!=n && nums[i]==nums[i-1])
            continue;
            v.push_back(nums[i]);
            backtrack(nums,v,ans,i+1);
            v.pop_back();
        }

        
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;

        sort(nums.begin(),nums.end());
        vector<int> v;

        backtrack(nums,v,ans, 0);
        return ans;
    }
};


   