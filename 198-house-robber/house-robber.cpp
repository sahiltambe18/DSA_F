// brute force
// class Solution {
//     int mx = 0;
//     int pick(vector<int>& nums , int idx ){
       
//        if(idx<0){
//         return 0;
//        }

//        int loot  = max(pick(nums,idx-1),pick(nums,idx-2)+nums[idx]);
//        return loot;
//     }
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         return pick(nums,n-1);
//     }
// };

//time optimised O(n)
// class Solution {
//     int mx = 0;
//     int pick(vector<int>& nums , int idx , vector<int>& v ){
       
//        if(idx<0){
//         return 0;
//        }

//        if(v[idx]>0) return v[idx];

//         v[idx] = max(pick(nums,idx-1, v),pick(nums,idx-2 , v)+nums[idx]);
//        return v[idx];
//     }
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> v(n,-1);
//         return pick(nums,n-1 , v);
//     }
// };

//time-space optimised O(n)
class Solution {
    
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        // vector<int> v(n,0);

        int v1 = nums[0];
        int v2 = max(nums[1],nums[0]);

        for(int i = 2 ; i < n ;i++){
            int temp = max(v2,v1+nums[i]);
            v1 = v2;
            v2 = temp;
        }

        return max(v1,v2);
    }
};

