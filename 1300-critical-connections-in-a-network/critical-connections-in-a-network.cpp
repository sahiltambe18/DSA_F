class Solution {
    vector<vector<int>> ans;
    void dfs(vector<vector<int>>& connections , vector<int> &v , int src , int par , vector<int> &step , vector<int> &low , int cnt){
        if(v[src]) return;
        v[src] = 1;
        step[src] = cnt;
        low[src] = cnt;
        for(auto &i : connections[src]){
            if(v[i]) continue;
            dfs(connections , v , i , src , step , low , cnt+1);
        }
        for(auto &i : connections[src]){
            if(i==par) continue;
            if(low[i]<low[src]){
                low[src] = low[i];
            }
        }

        if(low[src] > low[par]){
            ans.push_back({par,src});
        }

    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> step(n , n) , low(n,n);
        vector<int> v(n,0);
        vector<vector<int>> adj(n);
        for(auto &eg : connections){
            int u = eg[0];
            int v = eg[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(adj , v,0,0, step,low,1);
        return ans;
    } 
};

/*

0   1
1   1
2   1
3   4
*/