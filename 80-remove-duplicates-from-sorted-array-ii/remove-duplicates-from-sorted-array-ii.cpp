class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
           if(count < 2 || nums[count-2]!=nums[i]){
               nums[count++] = nums[i]; 
           }
        }
        return count;
    }
};