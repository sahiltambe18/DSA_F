class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0 ; i < nums.size() ;i++){
            int idx = abs(nums[i]);
            if(nums[idx]<0){
                return idx;
            }else{
                nums[idx]*=-1;
            }
        }
        return 0;
    }
};