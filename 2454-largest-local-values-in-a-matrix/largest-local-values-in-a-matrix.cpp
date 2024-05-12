class Solution {

    int bfs(vector<vector<int>> &grid , int i , int j){
        int ele = grid[i][j];
        for(int y = i-1 ; y <= i+1 ; y++){
            for(int x = j-1 ; x <=j+1 ; x++ ){
                ele = max(ele , grid[y][x]);
            }
        }
        return ele;
    }
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n-2 , vector<int>(n-2,0));
        for(int i = 1; i < n-1 ; i++){
            for(int j = 1 ; j < n-1 ; j++){
                ans[i-1][j-1] = bfs(grid , i , j);

            }
        }
        return ans;
    }
};