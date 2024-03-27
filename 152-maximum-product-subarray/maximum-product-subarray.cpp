class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];

        int prod = 1 , mx = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            
             
            prod*=nums[i];
            if(mx<prod){
                mx = prod;
            }
            if(prod==0) prod=1;

        }
        prod = 1;
        for(int i = n-1 ; i>=0 ; i--){
            
            prod*=nums[i];
            if(prod>mx) mx =prod;
            if(prod==0) prod=1;
        }

        return mx;
    }
};