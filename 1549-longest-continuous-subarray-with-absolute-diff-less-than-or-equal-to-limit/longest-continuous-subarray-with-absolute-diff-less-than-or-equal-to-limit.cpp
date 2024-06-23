class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int>  inc ;
        deque<int>  dsc ;

        int st = 0 , ed = 0;
        int n = nums.size() , ans = 0;

        while( ed < n){
            while(!inc.empty() && nums[inc.back()]>nums[ed]) inc.pop_back();
            inc.push_back(ed);

            while(!dsc.empty() && nums[dsc.back()]<nums[ed]) dsc.pop_back();
            dsc.push_back(ed);

            int mn = nums[inc.front()];
            int mx = nums[dsc.front()];

            while( mx-mn >limit ){
                st++;
                if(st>inc.front()) inc.pop_front();
                if(st>dsc.front()) dsc.pop_front();
                if(!inc.empty()) mn = nums[inc.front()];
                if(!dsc.empty()) mx = nums[dsc.front()];
            }
            ans = max(ans,ed-st+1);
            ed++;
        }

        return ans;

    }

};
