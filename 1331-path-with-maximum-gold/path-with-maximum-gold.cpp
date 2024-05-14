class Solution {
    int solve(vector<vector<int>>& grid , int i , int j ){
        if(grid[i][j]==0 ){
            return 0;
        }
        int val = grid[i][j];
        grid[i][j] = 0;
        int mx = 0;
        if(i<grid.size()-1){
            mx = max(mx , solve(grid,i+1,j));
        }if(i>0){
            mx = max(mx , solve(grid,i-1,j));
        }if(j<grid[0].size()-1){
            mx = max(mx , solve(grid,i,j+1));
        }if(j>0){
            mx = max(mx , solve(grid,i,j-1));
        }
        grid[i][j] = val;

        return mx+val;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int mx = 0;
        for(int i = 0 ; i < grid.size();i++){
            for(int j = 0 ; j < grid[0].size();j++){
                mx = max(mx , solve(grid , i , j));
            }
        }
        return mx;
    }
};