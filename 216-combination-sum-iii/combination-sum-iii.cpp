class Solution {
    void backtrack(int k , int sum , int ind , vector<vector<int>> &ans , vector<int> &v){
        if(k==0 && sum==0){
            ans.push_back(v);
            return;
        }
        if(sum<0 || k<0 ) return;

        if(ind > 9 ) return;
        v.push_back(ind);
        backtrack(k-1,sum-ind,ind+1,ans,v);
        v.pop_back();
        backtrack(k,sum,ind+1,ans,v);

    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> v;
        backtrack(k,n ,1,ans,v);
        return ans;
    }
};