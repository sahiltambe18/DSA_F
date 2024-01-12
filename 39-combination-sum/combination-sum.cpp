class Solution {
    void backtrack(vector<vector<int>> &ans , vector<int> &cand ,vector<int> &v  , int target , int idx){
        //base cases
        if(0==target){
            ans.push_back(v);
            return;
        }
        else if(0>target) return;
        
        for(int i = idx ; i < cand.size();i++){
            v.push_back(cand[i]);
            backtrack(ans ,cand , v ,target-cand[i],i);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        
        vector<vector<int>> ans;
        vector<int> v;

        backtrack(ans , cand,v , target , 0);
        return ans;
    }
};