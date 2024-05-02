class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int,int> mp;
        int mx = 0;

        for(auto i : nums){
            if(abs(i)>abs(mx) && mp[-i]==1){
                mx = i;
            }
                mp[i] = 1;
            
        }
        return abs(mx)==0 ? -1 : abs(mx);
    }
};