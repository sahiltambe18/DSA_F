class Solution {
    void bk(int n , int k , int idx , vector<int> &v , vector<vector<int>> &ans){

        if(k==0){
            ans.push_back(v);
            return;
        }

        for(int i = idx ; i <=n ; i++){
            v.push_back(i);
            bk(n,k-1 , i+1,v,ans);
            v.pop_back();
        }

    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v;
        bk(n , k , 1 ,v, ans);
        return ans;
    }
};