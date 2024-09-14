class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = 0;
        for(auto &i:nums) {
            if(mx<i) mx =i;
        }
        int mxLen = 1;
        int len = 0;
        for(int i = 0 ; i < nums.size() ;i++){
            if(nums[i]<mx) len = 0;
            else{
                len++;
                mxLen = max(mxLen , len);
            }
        }
        return mxLen;

    }
};