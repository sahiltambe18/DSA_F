class Solution {
public:
    int specialArray(vector<int>& nums) {
         sort(nums.begin(),nums.end());
        int n = nums.size(); 

       for (int x = 0; x <= n; ++x) {

            int count = 0 , i =0;
            while(i<n && nums[i]<x) i++;
            count = n-i;
            if (count == x) {
                return x;
            }
        }

        return -1;
    }
};