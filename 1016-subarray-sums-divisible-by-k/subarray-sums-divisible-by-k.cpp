class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count = 0;
        int prefSum = 0;
        unordered_map<int,int> mp;
        mp[0]=1;

        for(auto i : nums){
            prefSum+=i;

            int mod = prefSum%k;
            mod+= mod<0 ? k : 0;

            if(mp.find(mod)!=mp.end()){
                count+=mp[mod];
                mp[mod]+=1;
            }else{
                mp[mod] = 1;
            }
        }
        
        return count;
    }
};