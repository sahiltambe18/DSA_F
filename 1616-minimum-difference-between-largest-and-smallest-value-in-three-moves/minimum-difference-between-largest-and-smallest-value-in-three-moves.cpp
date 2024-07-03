class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n<=4) return 0;
        
        sort(nums.begin(),nums.end());
        int d = INT_MAX;
        int i = 0 , j= n-4;

        while(i<=3){
            d = min(d , nums[j]-nums[i]);
            i++ , j++;
        }
        return d;
    }
};