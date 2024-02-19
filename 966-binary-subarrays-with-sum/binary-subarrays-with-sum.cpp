class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int cnt = 0;
        unordered_map<int, int> sumCount; // stores the count of prefix sums
        
        int sum = 0;
        sumCount[0] = 1; // for the case where the entire subarray sums up to the goal
        
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            cnt += sumCount[sum - goal]; // count of subarrays ending at index i
            sumCount[sum]++;
        }
        
        return cnt;
    }
};
