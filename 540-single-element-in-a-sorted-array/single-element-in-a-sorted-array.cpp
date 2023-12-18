class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0 , r = nums.size()-1;
        while(l<r){
            int mid = l +(r-l)/2;
                if(mid%2!=0){
                    mid--;
                }
                    if(nums[mid+1]==nums[mid]){
                        l = mid+2;
                    }else{
                        r = mid;
                    }
        }
        return nums[l];
    }
};