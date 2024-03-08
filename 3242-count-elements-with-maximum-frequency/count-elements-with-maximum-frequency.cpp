class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i : nums){
            mp[i]++;
        }

        
        int mx = 0;
        for(auto i : mp){
            mx = max(i.second,mx);
        }

        int ele = 0;
        for(auto i : mp){
            mx==i.second?ele++:ele+=0;
        }
        return ele*mx;
    }
};