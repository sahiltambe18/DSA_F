class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l = 0 , r = n-1 , mid = 0;

        while(mid<=r){
            if(nums[mid]==0){
                swap(nums[l],nums[mid]);
                l++ , mid++;
            }else if(nums[mid]==1){
                mid++;
            }else{
                swap(nums[mid],nums[r]);
                r--;
            }
        }

    }
};