class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> map;
    for(int i = 0 ; i < nums.size() ; i++){
        int j = nums[i];
        for(auto x : map){
            if(j + x.second == target){
                return { i , x.first};
            }
        }
        map[i] = j;
    }
    return {};
}
};