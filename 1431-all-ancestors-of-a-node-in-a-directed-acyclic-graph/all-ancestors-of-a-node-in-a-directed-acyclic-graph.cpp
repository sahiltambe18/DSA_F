class Solution {
    void dfs(vector<vector<int>> &g, vector<int> &v , int curr ){
        if(v[curr]){
            return;
        }
        v[curr] = 1;

        for(int i = 0 ; i < g[curr].size();i++){
            dfs(g ,v , g[curr][i]);
        }

    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        // vector<vector<int>> ans(n);
        for(auto e : edges){
            g[e[1]].push_back(e[0]);
        }

        for(int dest = 0 ; dest < n ; dest++){
            vector<int> v(n,0);
            for(int j = 0 ; j < g[dest].size() ; j++){
                dfs(g , v , g[dest][j]);
            }

            g[dest] = {};

            for(int i = 0 ; i < n ; i++){
                if(v[i]){
                    g[dest].push_back(i);
                }
            }

        }

        return g;


    }
};