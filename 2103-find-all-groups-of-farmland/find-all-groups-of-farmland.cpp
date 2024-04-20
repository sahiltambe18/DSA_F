class Solution {
    void solve(vector<vector<int>>& land , int x , int y  ,int &maxX , int &maxY ){
        
        if(land[x][y]!=1){
            return ;
        }else{
            land[x][y]=0;
            maxX = max(maxX,x);
            maxY = max(maxY , y);
        }

        int n = land.size();
        int l = land[0].size();

        if(y>0){
            solve(land , x , y-1 , maxX,maxY);
        }
        if(y<l-1){
            solve(land , x , y+1 , maxX,maxY);
        }
        if(x>0){
            solve(land , x-1 , y , maxX,maxY);
        }
        if(x<n-1){
            solve(land , x+1 , y , maxX,maxY);
        }
    }
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;

        int n = land.size();
        int l = land[0].size();

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < l ; j++){
                if(land[i][j]==1){
                    int maxX = i , maxY = j;
                    solve(land , i,j , maxX , maxY);
                    ans.push_back({i,j,maxX,maxY});
                }
            }
        }

        return ans;
    }
};