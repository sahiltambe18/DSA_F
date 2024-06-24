class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size() , ans = 0;
        int flips = 0;
        for(int i = 0 ; i < n ; i++){
            
            if(i-k>=0 && nums[i-k]==2) flips--;

            if((nums[i]+ flips)%2==0){
                if(i+k > n) return -1;

                ans++;
                flips++;
                nums[i]=2;
                
            }
        }

        return ans;

    }
};