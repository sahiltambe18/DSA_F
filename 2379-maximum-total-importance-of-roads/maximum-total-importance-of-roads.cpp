class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long> g(n,0);

        for(auto i : roads){
            g[i[0]]++;
            g[i[1]]++;
        }

        sort(g.begin(),g.end());

        long long ans = 0LL;

        for(int i = 0 ; i < n ; i++){
            ans+= (i+1)*g[i];
        }

        return ans;
    }
};