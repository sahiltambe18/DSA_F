class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int,int> mp;
        vector<int> v;
        for(auto i : nums){
            if(mp[i]==1){
                mp.erase(i);
            }else{
                mp[i] = 1;
            }
        }
        for(auto i : mp){
            v.push_back(i.first);
        }
        return v;
    }
};