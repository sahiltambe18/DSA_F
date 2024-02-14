class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int mini = INT_MAX;
        int sum =  0,j = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            sum+= nums[i];
            while(sum>=target){
                mini = min(mini,i-j+1);
                sum-=nums[j];
                j++;
            }
        }

        return mini==INT_MAX ? 0 : mini;
    }
};