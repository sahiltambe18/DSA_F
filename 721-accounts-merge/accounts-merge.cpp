class Disjoint_set
{
private:
    /* data */
    vector<int> rank, parent, size;

public:
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


class Solution {

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        Disjoint_set dsu(n);
        unordered_map<string,int> mp;

        // joint by owner
        for(int i = 0 ; i < n ; i++){
            for(int j = 1 ; j < accounts[i].size() ; j++){
                string mail = accounts[i][j];
                if(mp.find(mail)==mp.end()){
                    mp[mail] = i;
                }else{
                    int pm = dsu.findParent(mp[mail]);
                    int pi = dsu.findParent(i);
                    dsu.unionByRank(pm,pi);
                }
            }
        }

        // group togather
        unordered_map<int , vector<string>> grp;
        for(auto &[mail , i] : mp){
            int p = dsu.findParent(i);
            grp[p].push_back(mail);
        }

        // answer
        vector<vector<string>> ans;

        for(auto &[i , mails] : grp){
            sort(mails.begin(),mails.end());
            mails.insert(mails.begin() , accounts[i][0]);
            ans.push_back(mails);
        }

        return ans;

    }
};