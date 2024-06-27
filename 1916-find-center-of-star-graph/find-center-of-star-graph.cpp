class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> v;

        for(auto i : edges){
            if(v[i[0]]==1){
                return i[0];
            }else if(v[i[1]]==1){
                return i[1];
            }else{
                v[i[0]] = 1;
                v[i[1]] = 1;
            }
        }
        return -1;
    }
};