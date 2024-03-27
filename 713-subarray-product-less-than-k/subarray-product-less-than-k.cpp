class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        if(k<=1) return 0;

        int cnt = 0 , n = nums.size();
        int prod = 1 , l = 0;

        for(int i = 0 ; i<n ; ++i){
            prod *=nums[i];
            while( prod >= k){
                prod/=nums[l];
                l++;
            }

            cnt+=i-l+1; // valid 
        }     

        return cnt;
    }


};