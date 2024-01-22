class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<bool> v(nums.size()+1 , false);
        vector<int> ans;
        v[0]=true;
        for(int i : nums){
            if(v[i]){
                ans.push_back(i);
            }else{
                v[i] = true;
            }
        }
        for(int i = 0 ; i < v.size();i++){
            if(v[i]==false){
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};
// 0 1 2 3 4 