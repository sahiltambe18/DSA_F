class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long res = 0;
        int er = -1, l = -1, r = -1;

        for (int i = 0; i < nums.size(); ++i) {
            if (!(minK <= nums[i] && nums[i] <= maxK)) {
                er = i;
            }

            if (nums[i] == minK) {
                l = i;
            }

            if (nums[i] == maxK) {
                r = i;
            }

            res += max(0, min(l, r) - er);
        }

        return res;
    }
};