class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0 , count = 0;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            int ele = nums[i];
            int idx = i;
            while(i<n && ele==nums[i]) i++;
            if(i-idx>2 || i-idx==2){
                nums[j++] = ele;
                nums[j++] = ele;
            }else{
                nums[j++] = ele;
            }
            i--;
        }
        return j;
    }
};