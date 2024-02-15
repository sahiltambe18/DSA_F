class Solution {
public:
// longest perimeter of polygon that can be formed using sides in nums

    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long sum = 0;
        for(auto i : nums){
            sum+=i;
        }
        for(int i = nums.size()-1;i>=2;i--){
            sum-=nums[i];
            if(sum>nums[i]) return sum + nums[i];
        }
        return -1;
    }
};