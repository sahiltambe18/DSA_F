class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        for(int i = 1 ; i < arr.size() ; i++){
            arr[i] ^= arr[i-1];
        }
        vector<int> ans;

        for(auto &q : queries){
            int i = q[0];
            int j = q[1];
            int x = 0;
            if(i>0){
                x = arr[i-1]^arr[j];
            }else{
                x = arr[j];
            }
            ans.push_back(x);
        }
        return ans;
    }
};