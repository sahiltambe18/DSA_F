class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<long long> diff(n);
        for(int i = 0 ; i < n ; i++){
            diff[i] = (long long) (nums[i]^k)-nums[i] ;
        }
        sort(diff.begin(),diff.end() , greater<long long>());
        long long ans = accumulate(nums.begin(),nums.end(),0LL);
        for(int i = 0 ; i < n-1 ; i+=2){
            if(diff[i]+diff[i+1]>0){
                ans += diff[i]+diff[i+1]; 
            }else{
                break;
            }
        }
        return ans;
    }
};