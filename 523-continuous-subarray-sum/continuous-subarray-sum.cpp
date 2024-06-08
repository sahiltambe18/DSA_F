class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n<2) return false;
        unordered_map<int ,int> mp;
        mp[0] = -1;
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];
            nums[i]=sum%k;
            if(mp.find(nums[i])==mp.end()){
                mp[nums[i]] = i;
            }
            if(i-mp[nums[i]]>=2 ) return true;
        }
        return false;
    }
};