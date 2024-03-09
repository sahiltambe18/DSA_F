class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
    //  int n1 = nums1.size() , n2 = nums2.size();
    //  int i = 0 , j = 0 ;
     unordered_map<int,int> mp;
        for(int i : nums1){
            mp[i] = 2;
        }
        for(int i : nums2){
            if(mp[i]==2) return i;
        }
        return -1;
    }
};