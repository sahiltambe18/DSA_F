
class Solution {
    unordered_map<int,int> parent , size;
    int findParent(int u)
    {
        if(parent.find(u)==parent.end()){
            parent[u] = u;
            return u;
        }
        if (parent[u] == u)
            return u;
        
        return parent[u] = findParent(parent[u]);
    }

    void unionBySize(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);
        // same component
        if (pu == pv)
            return;
        if(size.find(pu)==size.end()){
            size[pu] = 1;
        }
        if(size.find(pv)==size.end()){
            size[pv] = 1;
        }
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
        // cout<<size[pu]<<" "<<size[pv];
    }

public:
    int longestConsecutive(vector<int>& nums) {
        int mx = 0;
        unordered_set<int> st;
        for(auto &i : nums){
            st.insert(i);
            size[i]=1;
        }
        for(auto &i : st){
            if(st.count(i-1)>0){
                unionBySize(i , i-1);
            }
            if(st.count(i+1)>0){
                unionBySize(i , i+1);
            }

            mx = max(mx , size[findParent(i)]);

            // st.insert(i);
            
        }
        return mx;
    }
};