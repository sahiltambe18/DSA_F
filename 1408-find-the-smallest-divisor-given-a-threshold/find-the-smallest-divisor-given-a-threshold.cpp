class Solution {
    bool isok(vector<int>& nums, int threshold,int div){
        int th = 0;
        for(auto i : nums){
            if(i%div!=0){
                th++;
            }
            th+= i/div;
        }
        return th<=threshold;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1 , r = *max_element(nums.begin(),nums.end());
        while(l<r){
            int mid = l + (r-l)/2;
            if(isok(nums,threshold,mid)){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        return l;
    }
};