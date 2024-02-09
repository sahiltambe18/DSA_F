class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans = 0;
        for(int i = 0 ; i < nums.size();i++){
            int minn = nums[i];
            int maxx = nums[i];

            for(int j = i+1; j < nums.size(); j++){
                minn = min(minn , nums[j]);
                maxx = max(maxx , nums[j]);
                ans+= maxx-minn;
            }
        }
        return ans;
    }
};