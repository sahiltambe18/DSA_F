class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int , int> map;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            map[nums[i]]++;
            if(map[nums[i]]>n/2) return nums[i];
        }
        return 0;
    }
};