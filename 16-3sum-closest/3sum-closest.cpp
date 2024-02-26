class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size() , diff = INT_MAX , ans = 0;
        for(int i = 0 ; i < n ; i++){
            int l = i+1;
            int r = n-1;
            while(l<r){
                int sum = nums[i]+nums[l]+nums[r];
                
                if(abs(sum-target)<diff){
                    diff = abs(sum-target);
                    ans = sum;
                }
                if(sum>target){
                    r--;
                }else{
                    l++;
                }
            }
        }
        return ans;
    }
};

/*

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        int result = 0;
        for (int i = 0; i < nums.size() - 2; i++) {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    return sum;
                } else if (abs(sum - target) < abs(ans)) {
                    ans = sum - target;
                    result = sum;
                }
                if (sum > target) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        return result;
    }
};

*/