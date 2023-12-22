class Solution {
    bool check(vector<vector<int>>& mat , int x , int y){
        int ele = mat[x][y];
        for(auto i: mat[x]){
            if(i>ele) return false;
        }
        for(int i = 0 ; i < mat.size() ; i++){
            if(mat[i][y]>ele) return false;
        }
        return true;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size() , cols = mat[0].size();
        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < cols ;j++){
                if(check(mat,i,j)) return {i,j};
            }
        }
        return {};
    }
};