class Solution {
    void solve(vector<vector<char>>& grid , int x , int y){
        
        if(grid[x][y]!='1'){
            return ;
        }else{
            grid[x][y] = '0';
        }
        int n = grid.size();
        int l = grid[0].size();
        if(x>0){
            solve(grid,x-1,y);
        }if(x<n-1){
            solve(grid,x+1,y);
        }if(y>0){
            solve(grid,x,y-1);
        }if(y<l-1){
            solve(grid,x,y+1);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int l = grid[0].size();
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j<l ; j++){
                if(grid[i][j]=='1'){
                    solve(grid , i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};