class Solution {
    void backtrack(vector<int> &c , int t , vector<int> &v , vector<vector<int>> &ans , int idx){
        if(t<0){
            return;
        }else if(t==0){
            ans.push_back(v);
            return;
        }

        for(int i = idx ; i < c.size() ; i++){
            if(i > idx && c[i]==c[i-1]) continue;
            if(t-c[i]>=0){
               v.push_back(c[i]);
               backtrack(c,t-c[i],v,ans,i+1);
               v.pop_back();
           }
        }

    }
public:
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(c.begin(),c.end());
        backtrack(c,t,v,ans , 0);
        return ans;
    }
};