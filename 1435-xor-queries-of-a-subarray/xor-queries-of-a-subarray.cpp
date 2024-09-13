class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto &q : queries){
            int i = q[0];
            int j = q[1];
            int x = 0;
            for(i ; i <=j ; i++){
                x^=arr[i];
            }
            ans.push_back(x);
        }
        return ans;
    }
};