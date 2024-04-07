class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        sort(nums.begin(),nums.end());

        int mid = n/2;
        ans+= abs(nums[mid]-k);
        nums[mid] = k;

        for(int i = mid-1; i >=0 && nums[i]>k ; i--){
            ans+= abs(nums[i]-k);
        }

        for(int i = mid+1 ; i < n && nums[i]<k;i++){
            ans+=abs(nums[i]-k);
        }

        return ans;

    }
};