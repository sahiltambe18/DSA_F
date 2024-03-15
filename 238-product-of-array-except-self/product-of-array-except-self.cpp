class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeros = 0 , zero = 0; 
        int mul = 1;
        for(int i = 0 ; i < nums.size() ;i++){
            if(nums[i]==0){
                zeros++;
                zero = i;
            }else{
                mul = mul*nums[i];
            }
        }
        vector<int> ans(nums.size(),0);
        if(zeros==1){
            ans[zero] = mul;
            return ans;
        }else if(zeros>1){
            return ans;
        }

        for(int i = 0 ; i < nums.size() ;i++){
            ans[i] = mul/nums[i];
            // mul = mul * nums[i];
        }
        return ans;
    }
};