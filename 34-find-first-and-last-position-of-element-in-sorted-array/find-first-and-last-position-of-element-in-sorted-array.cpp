class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = findFirstOccurrence(nums, target);
        int end = findLastOccurrence(nums, target);

        return {start, end};
    }

private:
    int findFirstOccurrence(const vector<int>& nums, int target) {
        int result = -1;
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] >= target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }

            if (nums[mid] == target) {
                result = mid;
            }
        }

        return result;
    }

    int findLastOccurrence(const vector<int>& nums, int target) {
        int result = -1;
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] <= target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }

            if (nums[mid] == target) {
                result = mid;
            }
        }

        return result;
    }
};
