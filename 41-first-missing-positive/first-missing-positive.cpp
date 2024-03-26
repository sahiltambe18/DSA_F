class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int ct = 1;
       for(auto i : nums){
        if(i<ct){
            continue;
        }else if(i==ct){
            ct++;
        }else{
            return ct;
        }
       }
       return ct;
    }
};