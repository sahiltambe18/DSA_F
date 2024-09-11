class Solution {

    class Disjoint_set
{
private:
    /* data */
public:
    vector<int> rank, parent, size;

    Disjoint_set(int n)
    {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findParent(int u)
    {
        if (parent[u] == u)
            return u;
        return parent[u] = findParent(parent[u]);
    }

    void unionByRank(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);
        // same component
        if (pu == pv)
            return;
        else if (rank[pu] < rank[pv])
        {
            parent[pu] = pv;
        }
        else if (rank[pv] < rank[pu])
        {
            parent[pv] = pu;
        }
        else
        {
            parent[pu] = pv;
            rank[pv]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);
        // same component
        if (pu == pv)
            return;

        if (size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};


public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        Disjoint_set dsu(n);
        if(connections.size() < n-1) return -1;
        for(auto ed : connections){
            int a = ed[0];
            int b = ed[1];
            int pa = dsu.findParent(a);
            int pb = dsu.findParent(b);
            if(pa==pb) continue;
            dsu.unionByRank(pa,pb);
        }
        set<int> st;
        for(int i = 0 ; i < n ; i++){
            st.insert( dsu.findParent(i));
        }
        return st.size()-1;
    }
};