class Solution {
public:

    int rob(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int p1 = 0 , p2 = 0;
        for(auto i:nums){
            int temp = p1;
            p1 = max(p2+i,p1);
            p2 = temp;
        }
        return p1;
    }
};