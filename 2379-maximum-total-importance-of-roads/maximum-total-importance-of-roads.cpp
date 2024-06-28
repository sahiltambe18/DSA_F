class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<vector<int>> g(n);

        for(auto edge : roads){
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }

        priority_queue<pair<int , int>> pq;

        for(int i = 0 ; i < n ; i++){
            pq.push({g[i].size(),i});
        }

        vector<int> v(n,0);

        while(!pq.empty()){
            v[pq.top().second] = n;
            n--;
            pq.pop();
        }

        long long ans = 0LL;

        for(auto edge : roads){
            ans+= v[edge[0]];
            ans+= v[edge[1]];
        }

        return ans;
    }
};