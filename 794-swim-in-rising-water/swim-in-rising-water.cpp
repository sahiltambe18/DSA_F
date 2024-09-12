class Solution {
public:
    bool bfs(vector<vector<int>>& grid , int mid){
        set<pair<int,int>> st;
        queue<pair<int,int>> q;
        int n = grid.size();

        q.push({0,0});
        st.insert({0,0});
        while(!q.empty()){
            auto[x , y] = q.front();
            q.pop();
            if(x==n-1 && y==n-1) return 1;
            // if(st.count({x,y})>0) continue;
            int dx[] = {0,0,-1,1};
            int dy[] = {1,-1,0,0};
            for(int i = 0 ; i < 4 ; i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(ny>=0 && ny<n && nx>=0 && nx<n && grid[nx][ny] <= mid){
                    if(st.count({nx,ny})==0){
                        q.push({nx,ny});
                        st.insert({nx,ny});
                    }
                }
            }
        }

        return 0;
        
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int l = grid[n-1][n-1] > grid[0][0] ? grid[n-1][n-1] : grid[0][0] ;
        int r = 0;
        for(int i = 0 ; i < n ; i++){
            int mx = *max_element(grid[i].begin() , grid[i].end());
            r = max(r , mx);
        }
        if(r<=l) return l;

        while(l<=r){
            int mid =  l + (r-l)/2;
            if(grid[0][0] > mid ) {
                l = grid[0][0];
            }
            if(bfs(grid , mid)){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return l;
    }
};