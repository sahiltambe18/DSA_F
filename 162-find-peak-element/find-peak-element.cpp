class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0 , r = n-1;
        // if(r==0){
        //     return 0;
        // }else if(r==1){
        //    return (nums[0] > nums[1]) ? 0 : 1;
        // }
        while(l<r){
            int mid = l + (r-l)/2;

            if ((mid == 0 || nums[mid] > nums[mid - 1]) && (mid == n - 1 || nums[mid] > nums[mid + 1])) {
                return mid;
            } 
            else if (nums[mid] < nums[mid + 1]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};