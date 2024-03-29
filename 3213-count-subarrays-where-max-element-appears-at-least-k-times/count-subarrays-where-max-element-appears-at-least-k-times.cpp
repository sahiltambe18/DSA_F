class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        int  mxe = nums[0] , n = nums.size() , l = 0;

        for(auto i : nums){
            mxe = max(mxe,i);
        }

        for(int i = 0 ; i < n ; i++){
            // mxe = max(mxe,nums[i]);
            if(nums[i]==mxe){
                k--;
            }

            while(k<=0){
                ans+=n-i;
                if(nums[l]==mxe){
                    k++;
                }
                l++;
            }

        }
        
        return ans;
    }
};