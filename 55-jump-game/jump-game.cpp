class Solution {
public:
    bool canJump(vector<int>& nums) {
        int f = 0 , n = nums.size();
        if(n==1) return true;
        for(int i = 0 ; i < n ; i++){
            if(f== i && nums[i]==0) return false;
            f= max(f,i+nums[i]);
            if(n-1<=f) return true;
        }
        return false;
    }
};