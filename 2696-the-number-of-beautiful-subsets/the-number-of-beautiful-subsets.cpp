class Solution {
        int cnt = 0;

    void backtrack(vector<int>& nums, int k, unordered_map<int, int> &freq , int idx) {
            int n = nums.size();
            if (idx == n) {
                if (!freq.empty()) { 
                    cnt++;
                }
                return;
            }
            
            
            backtrack(nums,k,freq, idx + 1);
            
            if (freq[nums[idx] - k] == 0 && freq[nums[idx] + k] == 0) {
                freq[nums[idx]]++;
                backtrack(nums,k,freq, idx + 1);
                freq[nums[idx]]--;
                
            }
        };

public:
    int beautifulSubsets(vector<int>& nums, int k) {
        
        
        unordered_map<int, int> freq;
        
        
        
        backtrack(nums,k,freq,0);
        return cnt;
    }
};
