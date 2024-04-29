class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        for(int bit = 0 ; bit<=20 ;bit++){
            int xorr = 0;
            for(auto num : nums){
                int bitVal = (1<<bit) & num;
                xorr = xorr ^ bitVal;
            }
            int kBitVal = (1<<bit) & k;
            if(kBitVal!=xorr){
                ans++;
            }
        }
        return ans;
    }
};