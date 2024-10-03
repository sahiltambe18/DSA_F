// #define d(v) v.begin() v.end()  
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum = accumulate(begin(nums),end(nums),0LL);
        int n = nums.size() , ans = n;
        int rem = sum%p;
        if(rem==0) return 0;

        unordered_map<int,int> mp;
        mp[0] = -1;
        long long pref =0; 
        for(int i = 0 ; i <n ;i++){
            pref+=nums[i];
            int t = pref%p;
            int req = (pref-rem+p)%p;
            if(mp.find(req)!=mp.end()){
                ans = min(ans,i-mp[req]);
            }
            mp[t] = i;
        }
        

        if(ans==n) return -1;
        return ans;
    }
};