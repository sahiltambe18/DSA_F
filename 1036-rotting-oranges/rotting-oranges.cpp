class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // set<pair<int,int>> st;
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        bool flag = 0;

        
        
        for(int i = 0 ; i < n;i++){
            for(int j = 0 ; j < m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }else if(grid[i][j]==1){
                    flag = true;
                }
            }
        }
        int ans = 0;

        if(q.empty() && !flag) return 0;

        while(!q.empty()){
            ans++;
            int l = q.size();
            while(l>0){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                l--;

                // grid[i][j]=2;
                if(i>0 && grid[i-1][j]==1){
                    grid[i-1][j]=2;
                    q.push({i-1,j});
                }
                if(i<n-1 && grid[i+1][j]==1){
                    grid[i+1][j]=2;
                    q.push({i+1,j});
                }
                if(j>0 && grid[i][j-1]==1){
                    grid[i][j-1]=2;
                    q.push({i,j-1});
                }
                if(j<m-1 && grid[i][j+1]==1){
                    grid[i][j+1]=2;
                    q.push({i,j+1});
                }
            }
        }



        for(int i = 0 ; i < n;i++){
            for(int j = 0 ; j < m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }

        return ans-1;

    }
};