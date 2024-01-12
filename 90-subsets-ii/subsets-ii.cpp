class Solution {
    void backtrack(vector<int> &nums , vector<int> &v , set<vector<int>> &st , int n){
        if(n==nums.size()){
            st.insert(v);
            return;
        }

        v.push_back(nums[n]);
        backtrack(nums,v,st,n+1);
        v.pop_back();
        backtrack(nums,v,st,n+1);

    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> st;
        vector<int> v;
        sort(nums.begin(),nums.end());
        backtrack(nums,v,st, 0);
        for(auto i : st){
            ans.push_back(i);
        }
        return ans;
    }
};