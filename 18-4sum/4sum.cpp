class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        set<vector<int>> set;
        sort(nums.begin(), nums.end());
        int n = nums.size();


        for(int i = 0 ; i < n-3 ; i++){
            
             for (int j = i + 1; j < n - 2; ++j) {
            
                 int l = j+1 ;
                 int r = n-1;
            
                 while(l<r){
                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[l] + (long long)nums[r];

                    if(sum == target){
                        set.insert({nums[i] , nums[j] ,nums[l] ,nums[r]});
                        l++;
                        r--;
                    }else if(sum<target){
                        l++;
                    }else{
                        r--;
                    }
                 }
             }
        }
        for(auto i : set){
            ans.push_back(i);
        }
        return ans;
    }
};