class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int l = 0 , r = 0;
        int mini = INT_MAX;

        int summ = accumulate(nums.begin(),nums.end(),0);
        if(summ<target){
            return 0;
        }
        int sum = 0;
        
        while(r<nums.size()){
            if(sum<target){
                sum+=nums[r];
                r++;
            }else{
                mini = min(mini , r-l);
                sum-=nums[l];
                l++;
            }
        }

        while(sum-nums[l]>=target){
            sum-=nums[l];
            l++;
        }

        mini = min(mini,r-l);


        return mini;
    }
};