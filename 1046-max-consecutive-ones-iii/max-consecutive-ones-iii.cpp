class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count = 0, zeroCount = 0;
        int start = 0, end = 0;

        for (end = 0; end < nums.size(); ++end) {
            if (nums[end] == 0) {
                zeroCount++;
            }

            while (zeroCount > k) {
                if (nums[start] == 0) {
                    zeroCount--;
                }
                start++;
            }

            count = max(count, end - start + 1);
        }

        return count;
    }
};
