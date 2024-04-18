class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int l = grid[0].size();
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < l ; j++){
                int k = grid[i][j];
                if(k==1){
                    ans+=4;
                    if(i>0  && grid[i-1][j]==1){
                        ans-=2;
                    }
                    if(j>0 && grid[i][j-1]==1){
                        ans-=2;
                    }
                }
            }
        }
        return ans;
    }
};