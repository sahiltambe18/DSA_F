class Solution {
    
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1 , r = *max_element(nums.begin(),nums.end());
        int ans = -1;
        while(l<=r){
        int mid = l + (r-l)/2;
        int th = 0;
        for(auto i : nums){
            if(i%mid!=0){
                th++;
            }
            th+= i/mid;
        }
        if(th<=threshold){
                r = mid-1;
                ans = mid;
        }else{
                l = mid+1;
            }
        }
        return ans;
    }
};