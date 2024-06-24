class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size() , ans = 0;
        deque<int> dq;
        for(int i = 0 ; i < n ; i++){
            
            while( !dq.empty() && i > k + dq.front()-1) dq.pop_front();

            if((nums[i]+ dq.size())%2==0){
                if(i+k > n) return -1;

                ans++;
                dq.push_back(i);
            }
        }

        return ans;

    }
};