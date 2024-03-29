class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        int  mxe = *max_element(nums.begin(),nums.end()) , n = nums.size() ;

        vector<int> ind;

        for(int i = 0 ; i < n ; i++){
            // mxe = max(mxe,nums[i]);
            if(nums[i]==mxe){
                ind.push_back(i);
            }

            int freq = ind.size();

            if(freq>=k){
                ans+= ind[freq-k]+1;
            }

        }
        
        return ans;
    }
};