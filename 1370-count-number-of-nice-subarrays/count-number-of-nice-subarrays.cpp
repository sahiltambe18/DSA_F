class Solution {
    int atMost(vector<int>& nums, int k){
        int l = 0 , n = nums.size();
        int ans = 0;
        for(int i = 0; i < n ;i++){
            if(nums[i]%2) k--;

            while(k<0){
                if(nums[l]%2) k++;
                l++;
            }
            ans+=i-l+1;
        }
        return ans;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums,k) - atMost(nums,k-1);
    }
};