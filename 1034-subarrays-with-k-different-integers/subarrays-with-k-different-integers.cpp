class Solution {
public:
    /* brute force
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int cnt =0;
        for(int i = 0 ; i < nums.size();i++){
            unordered_map<int,int> mp;
            for(int j = i ; j < nums.size();j++){
                mp[nums[j]]++;
                if(mp.size()==k){
                    cnt++;
                }
            }
        }
        return cnt; 
    }*/

    int atmost(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int l = 0 ,cnt =0;
        for(int i = 0 ; i < nums.size();i++){
            mp[nums[i]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]<=0){
                    mp.erase(nums[l]);
                }
                
                l++;
            }
            
            cnt+=i-l+1;
            
        }
        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k) - atmost(nums,k-1);
    }
};