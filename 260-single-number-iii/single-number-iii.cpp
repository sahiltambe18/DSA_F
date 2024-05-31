class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        // int n = nums.size();

        int xorr = 0;
        for(auto i : nums){
            xorr^=i;
        }

        int sep = 1;

        while(!(xorr&sep)) sep = sep<<1;

        int a = 0;
        int b = 0;

        for(auto i : nums){
            if(sep&i){
                a^=i;
            }else{
                b^=i;
            }
        }

        return {a,b};
    }
};