class Solution {
    void solve(vector<vector<int>>& isConnected, vector<bool> &v , int x){
        v[x]=1;
        for(int i = 0 ; i < isConnected.size() ; i++){
            if(isConnected[x][i] && !v[i]){
                solve(isConnected,v,i);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0 , n = isConnected.size();
        vector<bool> v(n,false);
        
        for(int i = 0 ; i < n ; i++){
            if(!v[i]){    
                ans++;
                v[i]=1;
                solve(isConnected,v , i);
            }
        }
        return ans;
    }
};