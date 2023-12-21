class Solution {
    bool check(vector<int>& nums, int k,int limit){
        int t=1;
        int sum=limit;
        for(auto i:nums){
            if(sum>=i) sum-=i;
            else{
                sum=limit;
                t++;
                if(sum<i) return 0;
                sum-=i;
            }
            if(t>k) return 0;
            
        }
        return 1;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int l = 1 , r = accumulate(nums.begin(),nums.end(),0);
        if(k==1) return r;
        while(l<r){
            int mid = l + (r-l)/2;
            if(check(nums,k,mid)){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        return l;
    }
};