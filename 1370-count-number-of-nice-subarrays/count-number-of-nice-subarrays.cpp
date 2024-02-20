class Solution {
    int atMost(vector<int> &v , int k){
        int l = 0;
        int res = 0;
        for(int i = 0 ; i < v.size();i++){
            if(v[i]%2){
                k--;
            }
            while(k<0){
                if(v[l]%2){
                    k++;
                }
                l++;
            }
            res+= i-l+1;
        }
        return res;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums,k) - atMost(nums,k-1);
    }
};