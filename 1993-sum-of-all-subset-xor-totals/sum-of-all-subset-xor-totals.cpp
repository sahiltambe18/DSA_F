class Solution {
    int ans = 0;
    void solve(vector<int>& nums , int idx , int xorSum){
        if(idx==nums.size()){
            ans+=xorSum;
            return ;
        }
        solve(nums,idx+1 , xorSum);
        xorSum^=nums[idx];
        solve(nums,idx+1 , xorSum);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        
        int n = nums.size() ;
        solve(nums,0 , 0);
        return ans;
    }
};