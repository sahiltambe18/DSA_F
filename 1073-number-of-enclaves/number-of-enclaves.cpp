class Solution {
    int di [4] = {1,-1,0,0};
    int dj [4] = {0,0,1,-1};

    void dfs(vector<vector<int>>& grid , vector<vector<int>>& v , int i  , int j){
        

        v[i][j] =1;
        for(int x = 0 ; x <4 ;x++){
            int ni = i+di[x];
            int nj = j+dj[x];

            if(ni>=0 && ni < grid.size() && nj >=0 && nj < grid[0].size() && grid[ni][nj]==1 && !v[ni][nj]){
                dfs(grid , v , ni , nj);
            }    

        }

    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>v(m,vector<int>(n,0));

        for(int i = 0 ; i < m ; i++){
            if(grid[i][0]==1){
                dfs(grid , v , i , 0);
            }
            if(grid[i][n-1]==1){
                dfs(grid , v , i , n-1);
            }
        }
        for(int i = 0 ; i < n ; i++){
            if(grid[0][i]==1){
                dfs(grid , v , 0 , i);
            }
            if(grid[m-1][i]==1){
                dfs(grid , v , m-1 , i);
            }
        }


        int ans = 0;

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j]==1 && !v[i][j]){
                    ans++;
                }
            }
        }

        return ans;

    }
};