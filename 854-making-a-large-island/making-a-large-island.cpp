

class Disjoint_set {
private:
    /* data */

public:
    vector<int> rank, parent, size;
    Disjoint_set(int n) {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int u) {
        if (parent[u] == u)
            return u;
        return parent[u] = findParent(parent[u]);
    }

    void unionByRank(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        // same component
        if (pu == pv)
            return;
        else if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pv] < rank[pu]) {
            parent[pv] = pu;
        } else {
            parent[pu] = pv;
            rank[pv]++;
        }
    }

    void unionBySize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        // same component
        if (pu == pv)
            return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        Disjoint_set dsu(n * n);
        bool flag =0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j]==1){
                    int x = (n*i)+j;
                    if(i-1>=0 && grid[i-1][j]){
                        int y = (n*(i-1))+j;
                        int px = dsu.findParent(x);
                        int py = dsu.findParent(y);
                        if(px!=py){
                            dsu.unionBySize(x,y);
                        }
                    }
                    if(j-1>=0 && grid[i][j-1]){
                        int y = (n*i)+j-1;
                        int px = dsu.findParent(x);
                        int py = dsu.findParent(y);
                        if(px!=py){
                            dsu.unionBySize(x,y);
                        }
                    }
                }else{
                    flag = 1;
                }
            }
        }

        int dx[] = {0,0,1,-1}; 
        int dy[] = {-1,1,0,0}; 
        int mx = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j]==0){
                    set<int> st;
                    for(int k = 0 ; k < 4 ; k++){
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if(x>=0 && x<n && y>=0 && y<n && grid[x][y]==1){
                            st.insert(dsu.findParent(n*x + y));
                        }
                    }
                    int size = 0;
                    for(auto ile : st){
                        size+= dsu.size[ile];
                    }
                    size++;
                    if(size>mx) mx = size;
                }
            }
        }
        if(!flag) return n*n;

        if(mx>n*n) return n*n;
        return mx;
        
    }
};