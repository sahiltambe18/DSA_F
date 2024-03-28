class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int mx = INT_MIN , n = nums.size() , l = 0;
        for(int r = 0; r<n ; r++){
            mp[nums[r]]++;
            if(mp[nums[r]]>k){
                while(mp[nums[r]]>k){
                    mp[nums[l]]--;
                    l++;
                }
            }
            mx = max(mx , r-l+1);
        }
        return mx;
    }
};