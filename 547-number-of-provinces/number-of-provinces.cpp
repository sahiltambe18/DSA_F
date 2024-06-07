class Solution {
    void solve(vector<vector<int>>& isConnected , int x){
        for(int i = 0 ; i < isConnected.size() ; i++){
            if(isConnected[x][i]==1){
                isConnected[x][i]=2;
                solve(isConnected , i);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0 , n = isConnected.size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(isConnected[i][j]==1){
                    ans++;
                    isConnected[i][j]=2;
                    solve(isConnected , j);
                }
            }
        }
        return ans;
    }
};